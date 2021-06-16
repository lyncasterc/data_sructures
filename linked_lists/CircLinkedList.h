#ifndef CircLinkedList_H
#define CircLinkedList_H

#include "Node.h"

class CircLinkedList
{
    private:
        Node *head;
    public:
        CircLinkedList(int arr[], int len)
        {
            initialize(arr, len);
        }

        void initialize(int arr[], int len)
            {
                Node *tail;
                head = new Node;
                head->value = arr[0];
                tail = head;

                for (size_t i = 1; i < len; i++)
                {
                    if(!tail->next_node)
                    {
                        tail->next_node = new Node;
                        tail->next_node->value = arr[i];
                        tail = tail->next_node;
                    }
                }
                tail->next_node = head;
            };

        void insert_at(int index, int value)
        {
            Node *prev_node, *node;
            int count = 0;
            prev_node = head;

            for (size_t i = 0; i < index - 1; i++)
            { prev_node = prev_node->next_node; }
            
            node = new Node;
            node->value = value;

            node->next_node = prev_node->next_node;
            prev_node->next_node = node;

        }

        bool check_loop()
            {
                Node *p;
                Node *q;
                p = q = head;

                while(p && q)
                {
                    p = p->next_node;
                    q = q->next_node->next_node;

                    if(p == q)
                    {
                        return true;
                    }
                }
                return false;
            }

        void display()
        {
            Node *node = head;

            do
            {
                if(node->next_node != head)
                {
                    cout << " ( " << node->value << " ) -> ";
                }
                else
                {
                    cout << " ( " << node->value << " )" << endl;
                    
                }

                node = node->next_node;
                
            } while (node != head);
            
        }

};

#endif