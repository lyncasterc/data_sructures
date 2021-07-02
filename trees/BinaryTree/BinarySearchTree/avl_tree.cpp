#include <iostream>
#include <array>
using namespace std;

class Node
{
    public:
        Node *left = NULL;
        Node *right = NULL;
        int height;
        int key;
};

class AVLTree
{
    public:
        Node *root = NULL;


        int height(Node *node)
        {
            if(!node)
            { return 0; }
            return node->height;
            
        }

        int max(int a, int b)
        { return (a > b) ? a : b; }

        int get_balance_factor(Node *node)
        {
            if(!node)
            { return 0; }
            return height(node->left) - height(node->right);
        }

        Node * ll_rotation(Node *node)
        {
            Node *nl = node->left;
            Node *nlr = nl->right;

            //rotation
            nl->right = node;
            node->left = nlr;

            // updating heights of nodes
            node->height = 1 + max(height(node->left), height(node->right));
            nl->height = 1 + max(height(nl->left), height(nl->right));
            
            //updating root if rotation was performed around root node
            if(root == node)
            { root = nl; }

            return nl;

        }

        Node *insert(Node *node, int key)
        {
            if(!node)
            {
                node = new Node;
                node->key = key;
                node->height = 1;
                return node;
            }

            if(key < node->key)
            { node->left = insert(node->left, key); }

            else if(key > node->key)
            { node->right = insert(node->right, key); }
                
            node->height = 1 + max(height(node->left), height(node->right));

            if(get_balance_factor(node) == 2 && get_balance_factor(node->left) == 1)
            { return ll_rotation(node); }

            return node; 


        }        

        
};

int main()
{
    AVLTree t;
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 1);

    cout << t.root->key;
}