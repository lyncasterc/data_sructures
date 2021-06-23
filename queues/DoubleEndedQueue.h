#ifndef DoubleEndedQueue_H
#define DoubleEndedQueue_H
#include <array>
#include <iostream>

using namespace std;

class DoubleEndedQueue
{
    private:
        int front;
        int rear;
        int size;
        int *arr;
    public:
        DoubleEndedQueue(int size)
        { 
            this->size = size;
            arr = new int[size];
            front = rear = -1;
        }

        void rear_enqueue(int value)
        {
            
        }

};


#endif