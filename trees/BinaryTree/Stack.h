#ifndef Stack_H
#define Stack_H
#include <array>
#include "Node.h"
#include <iostream>

using namespace std;

class Stack
{
    private:
        int size; 
        int top;
        Node **arr;
    public:

        Stack(int size)
        {
            this->size = size;
            arr = new Node*[size];
            top = -1;

        };

        void insert(Node *ele)
        {
            if(!is_full())
            { arr[++top] = ele; }
        }

        Node *pop()
        {
            if(!is_empty())
            { return arr[top--]; }
        }

        bool is_empty()
        {
            if(top == -1)
            { return true; }
            return false;
        };
        
        bool is_full()
        {
            if(top == size - 1)
            { return true; }

            return false; 
        }

};
#endif