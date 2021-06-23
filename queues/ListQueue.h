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
};
#endif