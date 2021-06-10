#ifndef LinkedList_H
#define LinkedList_H

#include <array>
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
    private:
        Node *head;
    public: 
        LinkedList()
        {
            head = NULL;
        };

        LinkedList(int arr[], int len)
        {
            initialize(arr,len);
        };

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
        };

        int length()
        {
            if (!head)
            { return 0; }

            Node *node = head;
            int count = 1;

            while(node->next_node)
            {
                count++;
                node = node->next_node;
            }

            return count;

        }

        int sum()
        {
            if(!head)
            { return 0; }

            Node *node = head;
            int result = 0;

            while(node->next_node)
            {
                result += node->value;
                node = node->next_node;
                
                if(!node->next_node)
                {
                    result += node->value;

                }
            }
            
            return result;

            
        };

        void display()
        {
            Node *node = head;

            if(!node)
            {
                cout << "NULL" << endl;
            }

            while(node->next_node)
            {
                cout << "( " << node->value << " )" << " -> ";
                node = node->next_node;

                if (!node->next_node)
                {
                    cout << "( " << node->value << " )" << " ->  NULL" << endl;
                }
                
            }
        }
};


#endif