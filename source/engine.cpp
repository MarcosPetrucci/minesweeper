#include "header/engine.h"
#include <iostream>

//Instantiate new player and new field
engine::engine(int qtt_mines, int size)
{
    ply = new player(qtt_mines);
    field_game = new field(size, qtt_mines);
}

//Destructor
engine::~engine()
{
    delete ply;
    delete field_game;
}

//Calls the attribute Field to present the complete field with all of its values
void engine::present()
{
    field_game->present_field();
}