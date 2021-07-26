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
            Node *node = new Node;
            node->value = val;

            
        }
        ~Hash()
        {
            delete [] hash_arr;
        }
};

int main()
{

}