#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

#include <array>
#include <iostream>
#include "Node2.h"

using namespace std;

class DoubleLinkedList
{
    private:
        Node2 *head;
    public:
        DoubleLinkedList()
        {
            head->prev_node = NULL;
            head->next_node = NULL;
        }

        DoubleLinkedList(int arr[],int n)
        {   
            initialize(arr, n);
        }

        void initialize(int arr[], int n)
        {
            head = new Node2;
            head->value = arr[0];
            Node2 *tail = head;

            for (size_t i = 1; i < n; i++)
            {
                tail->next_node = new Node2;
                tail->next_node->value = arr[i];
                tail->next_node->prev_node = tail;
                tail = tail->next_node;
            }
            
        };

        

};

#endif