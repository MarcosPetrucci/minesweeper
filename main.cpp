#include "header/engine.h"
#include <iostream>
#include <cstdlib>

int main(int argv, char **argc)
{
    int size, qtt_mines;
    if(argv < 2)
        std::cout << "\nPlease submit the minimum info\n";
    else
    {
        size = atoi(argc[1]);
        qtt_mines = atoi(argc[2]);
    }

    //Initialize the game
    engine *game = new engine(qtt_mines, size);   
    game->present();

    return 0;
}