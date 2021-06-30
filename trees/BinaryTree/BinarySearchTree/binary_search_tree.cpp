#include <iostream>
#include <array>

using namespace std;

class Node
{
    public:
        int data;
        Node *left_child = NULL;
        Node *right_child = NULL;
};

class BinarySearchTree
{   
    public:
        Node *root = NULL;

    int search(Node *node, int key)
    {
        if(!node)
        { return NULL; }
        
        if(node->data == key)
        { return node->data; }

        if(key < node->data)
        { return search(node->left_child, key); }

        if(key > node->data)
        { return search(node->right_child, key); }
    }

    Node *insert(Node *node, int key)
    {
        if(!node)
        {
            node = new Node;
            node->data = key;
            return node;
        }

        if(key < node->data)
        { node->left_child = insert(node->left_child, key); }

        else if(key > node->data)
        { node->right_child = insert(node->right_child, key); }

        return node;

    }
};

int main()
{
    BinarySearchTree t;
    t.root = t.insert(t.root, 4);

    cout << t.root->data;

    t.insert(t.root, 5);
    t.insert(t.root, 6);


    
}

