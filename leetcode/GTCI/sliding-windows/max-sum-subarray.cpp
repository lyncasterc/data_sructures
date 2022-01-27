#include <iostream>
#include <vector>
#include <algorithm>

// arr[i] > 0 so max_sum can be set to 0 from the start.
int max_sum_subarray(std::vector<int> arr, int k)
{
    int start = 0, sum = 0, max_sum = 0;

    for (size_t end = 0; end < arr.size(); end++)
    {
        sum += arr[end];


        if(end >= k - 1)
        {
            max_sum = std::max(max_sum, sum);
            sum -= arr[start++];
        }
    }
    
    return max_sum;
};

int main()
{
    std::vector<int> arr1 = { 2, 1, 5, 1, 3, 2 };
    std::vector<int> arr2 = { 2, 3, 4, 1, 5 };

    std::cout << max_sum_subarray(arr1, 3) << std::endl; // 9 
    std::cout << max_sum_subarray(arr2, 2) << std::endl; // 7
}