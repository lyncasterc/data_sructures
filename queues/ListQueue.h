#ifndef ListQueue_H
#define ListQueue_H

#include <iostream>
#include "Node.h"

using namespace std;

class ListQueue
{
    private:
        Node *front;
        Node *rear;
    public:
        ListQueue()
        { 
            front = rear = NULL;
        }

        void enqueue(int value)
        {
            if(is_full())
            { cout << "Queue is full" << endl; }

            else if(is_empty())
            {
                front = new Node;
                front->value = value;
                rear = front;
            }
            else
            {
                rear->next_node = new Node;
                rear = rear->next_node;
                rear->value = value;
            }
        }

        bool is_empty()
        {
            if(!front)
            { return true; }
            
            return false;
        }

        bool is_full()
        {
            Node *node = new Node;

            if (!node)
            { return true; }

            return false;

        }

        void display()
        {
            Node *node = front;

            while(node)
            {
                cout << node->value << " ";
                node = node->next_node;
            }
            cout << endl;
        }
};
#endif