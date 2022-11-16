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
    void end_game();    //Active only if step encounters a mine
public:
    engine(int qtt_mines, int size);
    ~engine();
    void begin_game();
    void step(int xx, int yy); //Player step in one position
    void mark_place(int xx, int yy); //Player marked a place as a possible mine
    void game_running(); //Check if the game is running
    void restart(); //For some reason the player wants to restart

    //Present the field with all the values (obviously is a dev function)
    void present();
};

#endif