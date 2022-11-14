#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>

// Define every place in the minesweeper
typedef struct place{
    bool isVisible = false;
    bool marked = false; //Marked as a mine or not
    int value = 0;
    /*
    -1 for mines
    0 for nothing, as the base value will be 0
    1, 2, 3... to be calculated
    */
}Place;

class field
{
private:
    int x; //Sizes of the field
    int mines_qtt;
    
    void generate_field();
    void place_mines(); //Function that places the mines in the field
    void calculate_neighbors(); //Calculate the neighboors values
    Place **mine_field; //Will be the field itself

public:    
    field(int x, int mines_qtt);
    ~field(); //Important to dealocate the field after
    int test_place(int xx, int yy);
    void mark_place(int xx, int yy);
    int getSize();
    void present_field(); //Dev function

};

/*
field::field()
field::~field()
*/

#endif