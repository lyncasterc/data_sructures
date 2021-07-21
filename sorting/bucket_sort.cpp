#include <iostream>
#include <array>

using std::cout;
using std::endl;

class Node
{
    public:
        int data;
        Node *next = nullptr;
};

void bucket_sort(int arr[], int size)
{
    int max = 0, j = 0;
    Node **bucket;
    Node *node; 

    //finding max 
    for (auto i = 0; i < size; i++)
    {
        if(arr[i] > max)
        { max = arr[i]; }
    }

    max++;
    // array of node pointers
    bucket = new Node* [max];

    //initializing each node to null

    for (auto i = 0; i < max; i++)
    {
        bucket[i] = nullptr;
    }

    for (auto i = 0; i < size; i++)
    {
        node = bucket[arr[i]];

        if(!node)
        {
            node = new Node;
            node->data = arr[i];
            bucket[arr[i]] = node;
        }
        else
        {
            while(node->next)
            {
                node = node->next;
            }
            node->next = new Node;
            node->next->data = arr[i];
        }
    
    }

    for (auto i = 0; i < max; i++)
    {
        node = bucket[i];

        while(node)
        {
            arr[j++] = node->data;
            node = node->next;
        }
        
    }
    


}

int main()
{
    int nums[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    bucket_sort(nums, size);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    
    
}