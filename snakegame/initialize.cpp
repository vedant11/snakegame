#include "Utilities.hpp"
#include "Game.hpp"

int main()
{
    randomNumberSeed();
    Game game = Game();
    while (1)
    {
        game.input();
        game.logic();
        // game.printGame();
    }
    return 0;
}