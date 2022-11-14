#include"header/player.h"

player::player(int qtt_mines)
{
    this->remaining_flags = qtt_mines;
}

void player::kill_player()
{
    is_alive = false;
}

void player::flag_positioned()
{
    remaining_flags--;   
}

void player::take_flag_back()
{
    remaining_flags++;
}

//Ci sta
player::~player(){}