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
            top = -1;
        }

        void push(int val)
        {
            arr[++top] = val;
        }

        void display()
        {
            if(top != -1)
            {
                for (size_t i = 0; i <= top; i++)
                {
                    cout << arr[i] << " " << endl;
                }
                
            }
        }

        ~ArrayStack()
        { delete [] arr; }
};

#endif