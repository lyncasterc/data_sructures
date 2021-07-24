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

int count_digits(int num)
{
    int count = 0;

    while (num != 0)
    {
        num /= 10;
        count++;
    }
    
    return count;
}

void radix_sort(int arr[], int size)
{
    int max = 0, j = 0, max_digits, divisor = 1, digit_index;
    Node **bucket = new Node*[10];
    Node *node; 

    // initializing nodes in bucket to null
    for (auto i = 0; i < 10; i++)
    {
        bucket[i] = nullptr;
    }
    
    //finding max 
    for (auto i = 0; i < size; i++)
    {
        if(arr[i] > max)
        { max = arr[i]; }
    }

    max_digits = count_digits(max);

    while (max_digits > 0)
    {
        for (auto i = 0; i < size; i++)
        {
            digit_index = (arr[i] / divisor) % 10;
            node = bucket[digit_index];

            if(!node)
            {
                node = new Node;
                node->data = arr[i];
                bucket[digit_index] = node;
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
        

        //copying bucket back into arr
        for (auto i = 0; i < 10; i++)
        {
            while(bucket[i])
            {
                node = bucket[i];
                arr[j++] = node->data;
                bucket[i] = bucket[i]->next;
                delete node;
            }
        }

        j = 0;
        divisor *= 10;
        max_digits--;
    }
    
    
}


int main()
{
    int nums[] = {237, 245, 43, 86, 13, 240, 36};
    int size = sizeof(nums) / sizeof(nums[0]);
    radix_sort(nums, size);
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
}