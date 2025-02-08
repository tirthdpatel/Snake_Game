#include "snake2.h"
#include<bits/stdc++.h>
using namespace std;
#define LENGTH 30
#define WIDTH 30

snake::snake(COORD p, int v) : vel(v), len(1) {
    head = new node(p);
    tail = head;
}

snake::~snake() {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void snake::change_dir(char d) {
    if ((dir == 'w' && d == 's') || (dir == 's' && d == 'w') ||
        (dir == 'a' && d == 'd') || (dir == 'd' && d == 'a')||(dir == 72 && d == 80) || (dir == 80 && d == 72) ||
        (dir == 75 && d == 77) || (dir == 77 && d == 75)) {
        return;
    }
    dir = d;
}

void snake::move_snake() {
    COORD new_head_pos = head->pos;

    switch (dir) {
        case 'w': new_head_pos.Y -= vel; break;
        case 'd': new_head_pos.X += vel; break;
        case 'a': new_head_pos.X -= vel; break;
        case 's': new_head_pos.Y += vel; break;
    }

    node* new_head = new node(new_head_pos);
    new_head->next = head;
    head = new_head;

    delete_tail();
}

void snake::delete_tail() {
    if (tail != head) {
        node* temp = tail;
        node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        tail = prev;
        tail->next = nullptr;
        delete temp;
    }
}

COORD snake::get_pos() {
    return head->pos;
}

bool snake::eaten(COORD food_pos) {
    return (food_pos.X == head->pos.X && food_pos.Y == head->pos.Y);
}

void snake::grow() {
    len++;
    node* new_node = new node(head->pos);
    tail->next = new_node;
    tail = new_node;
}

bool snake::collided() {
    if (head->pos.X < 1 || head->pos.X >= WIDTH-1  || head->pos.Y < 1 || head->pos.Y >= LENGTH ) {
        return true;
    }

    node* temp = head->next;
    while (temp) {
        if(temp==head->next){
            temp=temp->next;
            continue;
        }
        if (head->pos.X == temp->pos.X && head->pos.Y == temp->pos.Y) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

node* snake::get_body() {
    return head;
}


COORD snake::set_pos(int a,int b)
{
    head->pos.X=a;
    head->pos.Y=b;
    tail=head; len=0;
}