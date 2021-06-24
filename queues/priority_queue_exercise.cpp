#include <iostream>
#include <array>
using namespace std;



class Item 
{
    public:
        int value;
        int priority;
    

};

class Queue
{
    private:
        int front;
        int rear;
        int size;
        Item *arr;

    public:
        
        Queue(int size)
        {
            this->size = size;
            arr = new Item[size];
            front = rear = -1;
        }

        void enqueue(Item value)
        {
            if(!is_full())
            { arr[++rear] = value;  }
        }

        void dequeue()
        {
            if(!is_empty())
            { front++; }
        }

        bool is_empty()
        {
            if(front == rear)
            { return true; }
            return false;
        }

        bool is_full()
        {
            if(rear == size -1)
            { return true; }
            return false;
        }

};

class PriorityQueue
{
    private:
        int size;
        Queue *q1;
        Queue *q2;
        Queue *q3;

    public:
        PriorityQueue(int size)
        {
            this->size = size;
            q1 = new Queue(size);
            q2 = new Queue(size);
            q3 = new Queue(size);
        }

        void insert(int value, int priority)
        {
            if(priority >= 1 && priority <= 3)
            {
                Item *ele = new Item;
                ele->value = value;
                ele->priority = priority;
            }
            switch (priority)
            {
            case 1:
                q1->enqueue(ele);
                break;
            case 2:
                q1->enqueue(ele);

                break;
            case 2:
                q1->enqueue(ele);
                break;
            
            
            }
            
        }




};


int main()
{
}