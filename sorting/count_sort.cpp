#include <iostream>
#include <array>

using std::cout;
using std::endl;

void count_sort(int arr[], int size)
{
    int max = 0, j = 0;
    for (auto i = 0; i < size; i++)
    {
        if(arr[i] > max)
        { max = arr[i]; }
    }

    max++;
    
    int hash_arr[max]; 

    for (auto i = 0; i < max; i++)
    {
        hash_arr[i] = 0;
    }

    for (auto i = 0; i < size; i++)
    {
        hash_arr[arr[i]] += 1; 
    }

    for (auto i = 0; i < max; i++)
    {
        while (hash_arr[i] > 0)
        {
            arr[j++] = i;
            hash_arr[i]--;
        }
    }
    
    
}




int main()
{
    int nums[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    count_sort(nums, size);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    



}
