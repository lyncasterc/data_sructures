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

        void push(int value)
        {   
            if(!head)
            {
                head = new Node2;
                head->value = value;
            }
            else
            {
                Node2 *node = new Node2;
                node->value = value;
                tail()->next_node = node;
                node->prev_node = tail();

            }
        }

        void insert_at(int index, int value)
        {
            int len = length();
            index = (index % len +len) % len;

            if(index == 0)
            {
                unshift(value);
            }
            else if (index == len - 1)
            {
                push(value);
            }
            else
            {
                Node2 *node = new Node2;
                node->value = value;
                Node2 *index_node = at(index);

                index_node->prev_node->next_node = node;
                node->next_node = index_node;
                node->prev_node = index_node->prev_node;
                node->next_node = index_node;
                index_node->prev_node = node;

            }
        }

        void remove_at(int index)
        {
            int len = length();
            index = (index % len + len) % len;

            if(index == 0)
            {
                shift();
            }
            else if(index == len - 1)
            {
                pop();
            }
            else
            {
                Node2 *index_node = at(index);
                Node2 *prev = at(index - 1);
                Node2 *next = at(index + 1);

                prev->next_node = next;
                next->prev_node = prev;
                delete index_node;

            }
        }

        Node2* at(int index)
        {

            int count = 0;
            Node2 *node = head;
            int len = length();
            
            while(node)
            {
                if(count == ((index % len + len) % len))
                { return node; }

                node = node->next_node;
                count++;
            }

            return NULL;
            
        }

        Node2 *tail()
        {
            Node2 *tail = head;
            
            while(tail->next_node)
            {
                tail = tail->next_node;
            }
            
            return tail;
        }

        void shift()
        {
            Node2 *node = head;
            if(!head->next_node)
            {
                head = NULL;
                delete node;
            }
            else
            {
                head->next_node->prev_node = NULL;
                head = head->next_node;
                delete node;
            }
            
        }

        void pop()
        {
            Node2 *node;

            if(!head->next_node)
            {
                node = head;
                head = NULL;
                delete node;
            }
            else
            {
                node = tail();
                at(-2)->next_node = NULL;
                delete node;
            }
        }

        void unshift(int value)
        {
            if(!head)
            {
                head = new Node2;
                head->value = value;
            }
            else
            {
                Node2 *node = new Node2;
                node->value = value;
                head->prev_node = node;
                node->next_node = head;
                head = head->prev_node;
                
            }
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

        int length()
        {
            if (!head)
            { return 0; }

            Node2 *node = head;
            int count = 1;

            while(node->next_node)
            {
                count++;
                node = node->next_node;
            }

            return count;
        }

        void display()
        {
            Node2 *node = head;

            while(node)
            {

                cout << "( " << node->value << " ) <- -> ";
                node = node->next_node;
                
            }

            if(!node)
            {
                cout << " NULL " << endl;
            }

        }

};

#endif