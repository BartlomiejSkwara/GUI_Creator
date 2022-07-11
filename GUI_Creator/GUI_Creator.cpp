#include "Code/GameLogic/Game.h"
#include <ctime>


int main()
{

    std::srand(static_cast<unsigned int>(NULL));


    Game game;

    while (game.windowIsOpen()) {
        game.update();
        game.render();

    }

    return 0;
}