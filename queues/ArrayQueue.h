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
            if(!is_full())
            {
                arr[++rear] = val;
            }
        }

        void dequeue()
        {
            if(!is_empty())
            {
                arr[++front] = NULL;
            }
        }

        void display()
        {
            for (size_t i = front + 1; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        int first()
        {
            if(!is_empty())
            { return arr[front + 1]; }
            return -1;
            
        }
        int last()
        {
            if(!is_empty())
            { return arr[rear]; }
            return -1;

        }

        bool is_empty()
        {
            if (front == rear)
            { return true; }

            return false;
        }

        bool is_full()
        {
            if(rear == size -1)
            { return true; }

            return false;
        }
};

#endif
