#ifndef ListStack_H
#define ListStack_H

#include <iostream>
#include "Node.h"

using namespace std;

class ListStack
{
    private:
        Node *top;
    public:
        ListStack()
        { top = NULL; }

        void push(int value)
        {
            if(!is_full())
            {
                if(is_empty())
                {
                    top = new Node;
                    top->data = value;
                }
                else
                {
                    Node *new_top = new Node;

                    new_top->data = value;
                    new_top->next = top;
                    top = new_top;
                }
            }
            else
            {
                cout << "Stack overflow" << endl;
            }
            
        }

        bool is_empty()
        {
            if(!top)
            { return true; }

            return false;
        }

        bool is_full()
        {
            Node *node = new Node;

            if(!node)
            {
                return true;
            }
            return false;
        }

        void display()
        {
            if(!is_empty())
            {
                Node *node = top;

                while(node)
                {
                    cout << node->data << endl;
                    node = node->next;
                }
            }
        }



};
#endif