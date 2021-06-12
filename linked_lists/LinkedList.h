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

        void unshift(int value)
        {
            Node *new_head = new Node;

            new_head->value = value;
            new_head->next_node = head;
            head = new_head;
        }

        Node* tail()
        {
            Node *tail = head;
            
            while(tail->next_node)
            {
                tail = tail->next_node;
            }
            
            return tail;
        }

        Node* at(int index)
        {

            int count = 0;
            Node *node = head;
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

        void insert(int index, int value)
        {
            int len = length();

            if (index == 0 || index == -len)
            { unshift(value); }

            else if (index == -1 || index == len - 1)
            { push(value); }
            
            else
            {
                Node *node = new Node;
                Node *prev_node;

                node->value = value;
                node->next_node = at(index);

                prev_node = at(index - 1);
                prev_node->next_node = node;
            }
        }

        void sorted_insert(int value)
        {
            int len = length();

            for (size_t i = 1; i < len; i++)
            {
                if( at(i-1)->value > value)
                { 
                    insert(i-1, value); 
                    break; 
                }
                if (i == len - 1 && at(i)->value < value)
                {
                    push(value);
                    break;
                }

            }
            
        }

        void push(int value)
        {
            if(!head)
            {
                head = new Node;
                head->value = value;
            }
            else
            {
                Node *node = new Node;
                node->value = value;
                tail()->next_node = node;
            }


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

        int max()
        {
            Node *node = head;
            int max = 0;
            
            if(!head)
            { return INT_MIN; }
            
            while(node)
            {
                if(node->value > max)
                {
                    max = node->value;
                }
                node = node->next_node;
            }

            return max;
        };

        int find(int key)
        {
            Node *node = head;
            int count = 0;

            while(node)
            {
                if (node->value == key)
                { return count; }
                node = node->next_node;
                count++;
            }
            return NULL;
        }

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