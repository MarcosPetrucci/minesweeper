#ifndef engine_H
#define engine_H

#include "field.h"
#include "player.h"

//Uses all the other classes to really "be" the game, will probably use GUI in the future
class engine
{
private:
    player *ply;
    field *field_game;
public:
    engine(int qtt_mines, int size);
    ~engine();
    //void begin_game();
    //Present the field with all the values (obviously is a dev function)
    void present();
};

#endif