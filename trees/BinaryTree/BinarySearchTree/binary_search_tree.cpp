#include <iostream>
#include <array>

using namespace std;

class Node
{
    public:
        int key;
        Node *left = NULL;
        Node *right = NULL;
};

class BinarySearchTree
{   
    public:
        Node *root = NULL;

    int search(Node *node, int key)
    {
        if(!node)
        { return NULL; }
        
        if(node->key == key)
        { return node->key; }

        if(key < node->key)
        { return search(node->left, key); }

        if(key > node->key)
        { return search(node->right, key); }
    }

    Node *insert(Node *node, int key)
    {
        if(!node)
        {
            node = new Node;
            node->key = key;
            return node;
        }

        if(key < node->key)
        { node->left = insert(node->left, key); }

        else if(key > node->key)
        { node->right = insert(node->right, key); }

        return node;
    }

    Node *min_val_node(Node *node)
    {
        Node *current = node;

        while(current && current->left)
        { current = current->left; }

        return current;
    }

    Node *delete_node(Node *node, int key)
    {
        if(!node)
        { return node; }

        if(key < node->key)
        { node->left = delete_node(node->left, key); }

        else if (key > node->key)
        { node->right = delete_node(node->right, key); }

        else
        {
            if(!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            
            Node *temp = min_val_node(node->right);
            node->key = temp->key;   
            node->right = delete_node(node->right, temp->key);

        }
        return root;
    }
};

int main()
{
    BinarySearchTree t;
    t.root = t.insert(t.root, 4);

    cout << t.root->key;

    t.insert(t.root, 5);
    t.insert(t.root, 6);

    


    
}

