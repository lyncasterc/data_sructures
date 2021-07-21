#include <iostream>
#include <array>

using std::cout;
using std::endl;

void merge(int arr[], int start, int mid, int end)
{
    int i = start;
    int j = mid+1;
    int k = start;
    int merged_arr[end + 1];

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            merged_arr[k++] = arr[i++];
        } 
        else 
        {
            merged_arr[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        merged_arr[k++] = arr[i++];
    }

    while (j <= end)
    {
        merged_arr[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = merged_arr[i];
    }
}


void loop_merge_sort(int arr[], int size)
{
    int start, mid, end, p;

    for (p = 2; p <= size; p *= 2)
    {
        for (auto i = 0; i + p - 1 < size; i += p)
        {
            start = i;
            end = i + p - 1;
            mid = (start + end) / 2;
            merge(arr, start, mid, end);
        }
    
    }

    if (p/2 < size)
    { merge(arr, 0, p / 2, size - 1); }
    
}

void merge_sort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = (end + start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);


    }
}

int main()
{
    int nums[] = {8, 3, 7, 4, 9, 2, 6, 5};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    merge_sort(nums, 0, nums_size - 1);


    for (auto &&i : nums)
    {  
        cout << i << " ";
    }
    


}