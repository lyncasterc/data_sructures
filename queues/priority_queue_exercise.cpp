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

        void enqueue(Item ele)
        {
            if(!is_full())
            { arr[++rear] = ele;  }
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

        int first()
        {
            if(!is_empty())
            {
                return arr[front + 1].value;
            }
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
                Item ele;
                ele.value = value;
                ele.priority = priority;
                switch (priority)
                {
                case 1:
                    q1->enqueue(ele);
                    break;
                case 2:
                    q2->enqueue(ele);

                    break;
                case 3:
                    q3->enqueue(ele);
                    break;
                }
            }
            
        }

        int get_highest_priority()
        {
            if(!q1->is_empty())
            {
                return q1->first();
            }
            else if(!q2->is_empty())
            {
                return q2->first();
            }
            else
            {
                return q3->first();
            }
            return -1;
        }

        void delete_highest_priority()
        {
            if(!q1->is_empty())
            {
                q1->dequeue();
            }
            else if(!q2->is_empty())
            {
                q2->dequeue();

            }
            else
            {
                q3->dequeue();
            }
        }

};


int main()
{
    PriorityQueue q(10);

    q.insert(10, 1);
    q.insert(5, 2);
    q.insert(1, 3);

    cout << q.get_highest_priority() << endl;
    q.delete_highest_priority();
    cout << q.get_highest_priority() << endl;

    q.insert(69,1);
    q.delete_highest_priority();
    q.delete_highest_priority();


    cout << q.get_highest_priority() << endl;


    


}