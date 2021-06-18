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
            if(!is_full())
            { arr[++top] = val; }
            else
            { cout << "Stack overflow" << endl;}
        }

        int pop()
        {
            int value = -1;

            if(is_empty())
            { cout << "Stack underflow" << endl; }
            else
            { value = arr[top--]; }

            return value;
        }

        bool is_empty()
        {
            if(top == -1)
            { return true; }
            return false;
        }

        bool is_full()
        {
            if(top == size - 1)
            { return true; }

            return false;
        }

        int peek(int pos)
        {
            if(!is_empty())
            {
                int len = top + 1, index;
                index = (-pos % len + len) % len;
                return arr[index];
            }
            return -1;
        }

        int stack_top()
        {
            if(!is_empty())
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