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

        int stack_top()
        {
            if(top != -1)
            { return arr[top]; }
            
            return NULL;
        }

        void display()
        {
            if(top != -1)
            {
                for (int i = top + 1; i-- > 0; )
                {
                    cout << arr[i] << endl << endl;
                }
                
            }
        }

        ~ArrayStack()
        { delete [] arr; }
};

#endif