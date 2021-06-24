#ifndef DEQueue_H
#define DEQueue_H
#include <array>
#include "ArrayQueue.h"
#include <iostream>

using namespace std;

class DEQueue : public ArrayQueue
{
    public:
        using ArrayQueue::ArrayQueue;

        void rear_dequeue()
        {
            if(!is_empty())
            {
                arr[rear] = NULL;
                rear = (rear - 1) % size;
            }
        }


};
#endif