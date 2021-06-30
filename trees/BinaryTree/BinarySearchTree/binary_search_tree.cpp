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

    Node *min_val_node(Node *node)
    {
        Node *current = node;

        while(current && current->left_child)
        { current = current->left_child; }

        return current;
    }

    Node *delete_node(Node *node, int key)
    {
        if(!node)
        { return node; }

        if(key < node->data)
        { node->left_child = delete_node(node->left_child, key); }

        else if (key > node->data)
        { node->right_child = delete_node(node->right_child, key); }

        else
        {
            if(!node->left_child)
            {
                Node *temp = node->right_child;
                delete node;
                return temp;
            }
            else if (!node->right_child)
            {
                Node *temp = node->left_child;
                delete node;
                return temp;
            }
            
            Node *temp = min_val_node(node->right_child);
            node->data = temp->data;   
            node->right_child = delete_node(node->right_child, temp->data);

        }
        return root;
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

