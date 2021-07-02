#include <iostream>
#include <array>
using namespace std;

class Node
{
    public:
        Node *left;
        Node *right;
        int height;
        int key;
};

class AVLTree
{
    public:
        Node *root = NULL;

        Node *insert(Node *node, int key)
        {
            if(!node)
            {
                node = new Node;
                node->key = key;
                node->height = 0;
                return node;
            }

            if(key < node->key)
            { node->left = insert(node->left, key); }

            else if(key > node->key)
            { node->right = insert(node->right, key); }


            return node;
        }

        int height(Node *node)
        {
            if(!node)
            { return 0; }
            return node->height;
        }
};

int main()
{

}