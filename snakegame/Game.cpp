#include "Game.hpp"
#include "Coordinates.hpp"
#include "Utilities.hpp"
#include <iostream>

Game::Game() : gameOver(false),
               width(20), height(20),
               fruit(nullptr),
               score(0),
               dir(up), snakeSize(1)
{
    this->borderSetUp();
    this->fruitSetUp();
    this->snakeSetUp();
    // this->printGame();
}

void Game::snakeSetUp()
{
    Coordinates head(this->width / 2, this->height / 2);
    this->snake[0] = &head;
    this->snake[1] = nullptr;
    head.draw('O');
}
void Game::borderSetUp()
{
    clearScreen();
    for (int i = 0; i < this->height; i++)
    {
        std::cout << "#";
        for (int j = 0; j < this->width - 2; j++)
        {
            if (i == 0 || i == this->height - 1)
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << "#";
    }
}
void Game::fruitSetUp()
{
    int x_temp = randomNumber() % (this->width - 2) + 1,
        y_temp = randomNumber() % (this->height - 2) + 1;
    Coordinates coord_temp(x_temp, y_temp);
    this->fruit = &coord_temp;
    for (int i = 0; i < 50; i++)
        if (x_temp == this->snake[i]->getX() && y_temp == this->snake[i]->getY())
            fruitSetUp();
}
void Game::input()
{
    if (keyHit())
    {
        switch (getChar())
        {
        case KEY_UP:
            this->dir = up;
            this->logic();
            break;
        case KEY_DOWN:
            this->dir = down;
            this->logic();
            break;
        case KEY_LEFT:
            this->dir = left;
            this->logic();
            break;
        case KEY_RIGHT:
            this->dir = right;
            this->logic();
            break;
        default:
            break;
        }
    }
}
void Game::logic()
{
    // elongate if ate a fruit.
    if ((this->snake[0]->getX() == fruit->getX()) && (this->snake[0]->getY() == this->fruit->getY()))
    {
        this->snake[this->snakeSize]->setCoordinates(
            this->snake[this->snakeSize - 1]->getX(),
            this->snake[this->snakeSize - 1]->getY());
        this->snakeSize++;
        this->fruitSetUp();
    }
    // trace whole body forward except the head
    for (int i = snakeSize - 1; i >= 1; i--)
    {
        this->snake[i]->setCoordinates(this->snake[i - 1]->getX(), this->snake[i - 1]->getY());
    }
    // move the head as per input
    switch (this->dir)
    {
    case up:
        this->snake[0]->moveUp();
        break;
    case down:
        this->snake[0]->moveDown();
        break;
    case left:
        this->snake[0]->moveLeft();
        break;
    case right:
        this->snake[0]->moveRight();
        break;
    default:
        break;
    }
    Coordinates *head = this->snake[0];
    // check if snake collides
    int head_x = head->getX(),
        head_y = head->getY();
    for (int i = 0; i < 50; i++)
    {
        if (this->snake[i] == nullptr)
            break;
        if (this->snake[i]->getX() == head_x && this->snake[i]->getY() == head_y)
        {
            this->gameOver = true;
            break;
        }
    }
    // fit snake in the border if it exceeds the box
    if (head->getX() < 0)
        head->setCoordinates(width - 1, head->getY());
    if (head->getX() >= this->width)
        head->setCoordinates(0, head->getY());
    if (head->getY() < 0)
        head->setCoordinates(head->getX(), this->height - 1);
    if (head->getY() >= this->height)
        head->setCoordinates(head->getX(), 0);
}