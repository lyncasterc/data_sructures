#ifndef ArrayStack_H
#define ArrayStack_H

#include <array>
#include <iostream>

using namespace std;

class ArrayStack
{
    private:
        int size;
        int top;
        int *arr;
    public:
        ArrayStack(int size)
        {
            this->size = size;
            arr = new int[size];
        }
};

#endif