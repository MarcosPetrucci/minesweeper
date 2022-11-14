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

void engine::present()
{
    field_game->present_field();
}