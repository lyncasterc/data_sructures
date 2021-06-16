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

            node = new Node;
            node->value = value;

            if(index == 0)
            {
                node->next_node = head;
                last()->next_node = node;
                head = node;
            }
            else
            {
                for (size_t i = 0; i < index - 1; i++)
                { prev_node = prev_node->next_node; }

                node->next_node = prev_node->next_node;
                prev_node->next_node = node;
            }

            

        }

        void shift()
        {
            Node *node = head;
            if(!head->next_node)
            {
                head = NULL;
                delete node;

            }
            else
            {
                last()->next_node = head->next_node;
                head = head->next_node;
                delete node;
            }
        }     

        void pop()
        {
            Node *node;
            if(head->next_node == head)
            {
                node = head;
                head = NULL;
                delete node;
            }
            else
            {
                node = last();
                at(-2)->next_node = head;
                delete node;
            }

            
        }

        Node *at(int index)
        {
            int len = length(), count = 0;
            index = (index % len + len) % len;
            Node *node = head;

            do
            {
                if(count == index)
                {
                    return node;
                }

                node = node->next_node;
                count++;
                
            } while (node != head);

            return NULL;
            
        }

        int length()
        {
            int count = 0;
            Node *node = head;

            if(!node)
            { return 0; }

            else
            {
                do
                {
                    count++;
                    node = node->next_node;
                } while (node != head);

            }
    
            return count;
        }

        Node *last()
        {
            Node *node = head;

            do
            {
                node = node->next_node;
            } while (node->next_node != head);

            return node;
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