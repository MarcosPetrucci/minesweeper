#include "header/field.h"
#include <stdlib.h>

field::field(int x, int mines_qtt)
{
    this->x = x;
    this->mines_qtt = mines_qtt;

    generate_field();
}

field::~field()
{   
    int i;
    for(i = 0; i < x; i++)
        free(mine_field[i]);
    
    free(mine_field[i]);

}//Important to dealocate the field after

//Generate the field using all the other functions
void field::generate_field()
{
    int i;

    //Generating the field by alloc x*x places
    this->mine_field = (Place**) malloc(x * sizeof(Place));
    for(i = 0 ; i < x; i++)
    {
        (this->mine_field)[i] = (Place*) malloc(x * sizeof(Place));
    }

    place_mines();
    //calculate_neighbors();
}

//Function that places the mines in the field
void field::place_mines()
{
    //Consider the field already populated
    int count_mines = 0;
    int xx, yy;

    //Complexity of mines_qtt, much better to run the entire matrix
    while(count_mines < mines_qtt)
    {
        //Generate random coordinates to place mines
        xx = rand()%x;
        yy = rand()%x;

        if(mine_field[xx][yy].value != -1)
        {
            mine_field[xx][yy].value = -1; //-1 for mines
            count_mines++;
        }
        else
            continue;
    }
} 

//Calculate the neighboors values
void field::calculate_neighbors()
{
    //Now, given that the field is sucessfully allocated and populated by mines
    int i, j;

    for(i = 0; i < x; i++)
    {
        for(j = 0; j < x; j++)
        {
            //This could be a function itself but for simplicity better let it here as it will
            // be only be used in this context

            //We can't be on a mine
            if(mine_field[i][j].value == -1)
                continue;
            else
            {
                //We have to garantee that the neighboor is a mine and is acessible
                if(mine_field[i-1][j-1].value == -1 && i > 0 && j > 0)
                    mine_field[i][j].value += mine_field[i-1][j-1].value;
                if(mine_field[i-1][j].value == -1 && i > 0)
                    mine_field[i][j].value += mine_field[i-1][j].value;
                if(mine_field[i-1][j+1].value == -1 && i > 0 && j < x-1 )
                    mine_field[i][j].value += mine_field[i-1][j+1].value;
                if(mine_field[i][j-1].value == -1 && j > 0)
                    mine_field[i][j].value += mine_field[i][j-1].value;
                if(mine_field[i][j+1].value == -1 && j < x-1)
                    mine_field[i][j].value += mine_field[i][j+1].value;
                if(mine_field[i+1][j-1].value == -1 && i < x-1 && j > 0)
                    mine_field[i][j].value += mine_field[i+1][j-1].value;
                if(mine_field[i+1][j].value == -1 && i < x-1)
                    mine_field[i][j].value += mine_field[i+1][j].value;
                if(mine_field[i+1][j+1].value == -1 && i < x-1 && j < x + 1)
                    mine_field[i][j].value += mine_field[i+1][j+1].value;
            }
            
                /*mine_field[i][j].value = mine_field[i-1][j-1].value + mine_field[i-1][j].value + mine_field[i-1][j+1].value +
                                    mine_field[i][j-1].value    + mine_field[i][j+1].value+
                                    mine_field[i+1][j-1].value + mine_field[i+1][j].value + mine_field[i+1][j+1].value; */
        }
    }
} 

int field::test_place(int xx, int yy)
{   
    if(mine_field[xx][yy].value == 1)
        return -1;
    else
        return 1;
}

void field::mark_place(int xx, int yy)
{
    mine_field[xx][yy].marked = true;
}

int field::getSize()
{
    return x;
}
