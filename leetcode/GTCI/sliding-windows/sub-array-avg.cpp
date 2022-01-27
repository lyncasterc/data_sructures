#include <iostream>
#include <numeric>
#include <vector>




std::vector<double> find_avg_of_subarrays(std::vector<int> &arr, int k)
{
    int start = 0;
    double sum = 0;
    std::vector<double> result;

    for (size_t end = 0; end < arr.size(); end++)
    {
        sum += arr[end];

        if(end >= k - 1)
        {
            result.push_back(sum / k);
            sum -= arr[start++];
        }
    }
    
    return result;
};



int main()
{
    std::vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    std::vector<double> result = find_avg_of_subarrays(arr, 5); //{ 2.2, 2.8, 2.4, 3.6, 2.8 }
    for (auto &&i : result)
    {
        std::cout << i << ", ";
    }
    
    
}