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

        
        
};
#endif