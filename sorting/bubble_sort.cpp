#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void bubble_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int greater_num = v[j];
                int less_num = v[j + 1];
                v[j] = less_num;
                v[j + 1] = greater_num;
            }
            else
            {
                continue;
            }
        }
    }
}



int main()
{
    vector<int> nums = {8, 5, 7, 3 ,2};
    bubble_sort(nums);
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    
}