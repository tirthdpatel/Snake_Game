#include "food.h"
#define LENGTH 30
#define WIDTH 30

food::food() {
    gen_food();
}

COORD food::get_pos() {
    return pos;
}

int food::gen_food() 
{
    srand(time(0));
    vector<int> cumalativeweight(6);
    int r=rand() % 100 +1;
    cumalativeweight[0]=weights[0];
    pos.X = (rand() % (WIDTH - 4)) + 2;
    pos.Y = (rand() % (LENGTH - 3)) + 2;
    for(size_t i=1;i<6;i++) cumalativeweight[i]=cumalativeweight[i-1]+weights[i];
    for(size_t i=0;i<6;i++)
    {
        if(r<=cumalativeweight[i]){K=i; break;}
    }
    return K;
}