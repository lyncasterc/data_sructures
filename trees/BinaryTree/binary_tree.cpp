#include <iostream>
#include <array>
#include "Node.h"
#include "Queue.h"

using namespace std;


class BinaryTree
{
    public:
        Node *root;
        BinaryTree()
        { root = NULL;}

        void create_tree()
        { 
            Node *p, *t;
            Queue q(100);
            int data;

            cout << "Enter root value: ";
            cin >> data;

            root = new Node;
            root->data = data;
            q.enqueue(root);

            while(!q.is_empty())
            {
                p = q.dequeue();
                cout << "Enter left child data (or -1 for NULL): ";
                cin >> data;
                if(data != -1)
                {
                    p->left_child = new Node;
                    p->left_child->data = data;
                    q.enqueue(p->left_child);
                }
                
                cout << "Enter right child data (or -1 for NULL)";
                cin >> data;

                if(data != -1)
                {
                    p->right_child = new Node;
                    p->right_child->data = data;
                    q.enqueue(p->right_child);
                }
            }
        }

        void preorder(Node *node)
        {
            if(node)
            {
                cout << node->data << " ";
                preorder(node->left_child);
                preorder(node->right_child);
                
            }
        };

        void inorder()
        {

        };
        void postorder();
        void levelorder();
        void height();


};

int main()
{
    BinaryTree tree;
    tree.create_tree();
    tree.preorder(tree.root);
}

