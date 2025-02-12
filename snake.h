#ifndef SNAKE_H
#define SNAKE_H
#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

struct node {
    COORD pos;
    node* next;
    node(COORD p) : pos(p), next(nullptr) {}
};

class snake
{
private:
    node* head;  
    node* tail;  
    char dir;    
    int vel,len;
public:
    vector<string> colour={"🟩","🟦","🟨","🟧","🟪","🟥"};
    snake(COORD pos, int vel);
    ~snake();
    void change_dir(char dir);
    void move_snake();
    COORD get_pos();  
    COORD set_pos(int a,int b);
    bool eaten(COORD food_pos);  
    void grow();  
    void delete_tail();  
    bool collided();
    node* get_body();  
};

#endif
