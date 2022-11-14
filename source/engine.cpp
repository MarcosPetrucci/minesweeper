#include "header/engine.h"
#include <iostream>

engine::engine(int qtt_mines, int size)
{
    ply = new player(qtt_mines);
    field_game = new field(size, qtt_mines);
}

engine::~engine()
{
    delete ply;
    delete field_game;
}

void engine::present_field_values()
{
    int i, j;
    for(i = 0; i < field_game->getSize(); i++)
    {
        for(j = 0; j < field_game->getSize(); j++)
        {
            std::cout << field_game->mine_field[i][j].value << " " ;
        }
        std::cout << "\n";
    }
}