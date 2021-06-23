#ifndef ArrayQueue_H
#define ArrayQueue_H

#include <array>
#include <iostream>
using namespace std;

class ArrayQueue
{
    private:
        int front;
        int rear;
        int size;
        int *arr;

    public:
        ArrayQueue(int size)
        {
            this->size = size;
            arr = new int[size];
            front = rear = -1;
        }

        void enqueue(int val)
        {
            arr[++rear] = val;
        }

        void display()
        {
            for (size_t i = front + 1; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

#endif
