#include <iostream>
#include <array>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

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

        void loop_pre(Node *node)
        {
            Queue q(100);
            Node *temp;
            q.enqueue(node);

            while(!q.is_empty())
            {
                temp = q.dequeue();
                cout << temp->data << " ";
                
            }
        }

        void inorder(Node *node)
        {
            if(node)
            {
                inorder(node->left_child);
                cout << node->data << " ";
                inorder(node->right_child);

            }
        };

        void postorder(Node *node)
        {
            if(node)
            {
                postorder(node->left_child);
                postorder(node->right_child);
                cout << node->data << " ";
            }
        };

        void levelorder(Node *node)
        {
            Queue q(100);
            Node *temp;
            q.enqueue(node);

            while(!q.is_empty())
            {
                temp = q.dequeue();
                cout << temp->data << " ";

                if (temp->left_child)
                { q.enqueue(temp->left_child); }

                if (temp->right_child)
                { q.enqueue(temp->right_child); }
                
            }
        };


        int height(Node *node)
        {
    
            if(!node)
            { return 0; }

            else
            {
                int left_count = height(node->left_child); 
                int right_count = height(node->right_child);

                    if (left_count > right_count)
                {   
                    return left_count + 1;
                }
                else
                {
                    return right_count + 1;
                }
            }
            
        };


};

int main()
{
    BinaryTree tree;
    tree.root = new Node;
    tree.root->data = 1;

    tree.root->right_child = new Node;
    tree.root->right_child->data = 3;

    tree.root->left_child = new Node;
    tree.root->left_child->data = 2;




    cout << tree.height(tree.root);
}

