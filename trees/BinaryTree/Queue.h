#ifndef Queue_H
#define Queue_H
#include <array>
#include "Node.h"

using namespace std;


class Queue
{
    private:
        int front;
        int rear;
        int size;
        Node **arr;

    public:
        
        Queue(int size)
        {
            this->size = size;
            arr = new Node*[size];
            front = rear = -1;
        }

        void enqueue(Node* ele)
        {
            if(!is_full())
            { arr[++rear] = ele;  }
        }

        Node* dequeue()
        {
            Node* node;
            if(!is_empty())
            { node = arr[++front]; }
            return node;
        }

        bool is_empty()
        {
            if(front == rear)
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