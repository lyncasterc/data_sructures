#include <iostream>
#include <array>

using std::cout;
using std::endl;

// takes a lot of space 
void count_sort(int arr[], int size)
{
    int max = 0, j = 0, *hash_arr;
    //finding max 
    for (auto i = 0; i < size; i++)
    {
        if(arr[i] > max)
        { max = arr[i]; }
    }

    max++;
    hash_arr = new int[max];

    // initializing hash_arr w/ 0
    for (auto i = 0; i < max; i++)
    {
        hash_arr[i] = 0;
    }

    // hashing arr in hash_arr
    for (auto i = 0; i < size; i++)
    {
        hash_arr[arr[i]] += 1; 
    }

    // copying hash values for each index back into arr
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
