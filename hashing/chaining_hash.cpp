#include <iostream>
#include <array>

using std::cout;
using std::endl;

class Node
{
    public:
        int value;
        Node *next = nullptr;
};

class Hash
{
    private:
        Node **hash_arr;
        int hash_function(int val)
        {
            return val % 10;
        }

    public:
        Hash()
        {
            hash_arr = new Node* [10];
        }

        void insert(int val)
        {
            int index = hash_function(val);
            Node *node = new Node, *temp;
            node->value = val;

            if(!hash_arr[index])
            {
                hash_arr[index] = node;  
            }
            else
            {
                Node *prev;
                temp = hash_arr[index];

                while(val >= temp->value && temp)
                {
                    prev = temp;
                    temp = temp->next;
                }

                if(!prev)
                {
                    if(temp == hash_arr[index])
                    {
                        node->next = hash_arr[index];
                        hash_arr[index] = node;
                    }
                    else
                    {
                        node->next = prev->next;
                        prev->next = node;
                    }
                }

            
            }

        }

        
        ~Hash()
        {
            delete [] hash_arr;
        }
};

int main()
{

}