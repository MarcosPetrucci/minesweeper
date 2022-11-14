#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>

// Define every place in the minesweeper
typedef struct place{
    bool isVisible = false;
    int value; //0 goes for mines, the rest is calculated based on that
}place;

class field
{
private:
    int x; //Sizes of the field
    int mines_qtt;
    place **mine_field; //Will be the field itself

    void generate_field();
    void place_mines(); //Function that places the mines in the field
    void calculate_neighbors(); //Calculate the neighboors values
    int test_place(int xx, int yy);
public:    
    field(int x, int mines_qtt);
    ~field(); //Important to dealocate the field after
};

/*
field::field()
field::~field()
*/

#endif