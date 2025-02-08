#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
#include<cstdlib>
#include<random>
#include<bits/stdc++.h>
using namespace std;
class food
{
private:
    COORD pos;

public:
    int K;
    vector<string> v={"=",">¿ ",">Z",">š",">¢",">©"}; 
    vector<int> weights = {25,25,25,5,10,10};
    vector<int> scores = {10,10,10,30,20,20};
    food();
    int gen_food();
    COORD get_pos();
};

#endif
