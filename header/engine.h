#ifndef engine_H
#define engine_H

#include "field.h"
#include "player.h"

//Uses all the other classes to really "be" the game, will probably use GUI in the future
class engine
{
private:
    player ply;
    field mine_field;
public:
    engine(/* args */);
    ~engine();
};

#endif