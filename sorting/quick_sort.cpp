#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void quick_sort(vector<int> &v, int start, int end)
{
    if((end - start) > 1)
    {
        int pivot = v[start], i = 1, j = end - 1, temp;
        while(j > i)
        {
            if(v[i] > pivot && v[j] <= pivot)
            { 
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
                j--;

            }
            if(v[i] <= pivot)
            {
                i++;
            }

            if(v[j] > pivot)
            {
                j--;
            }
        
        }

        temp = v[j];
        v[j] = pivot;
        v[start] = temp;

        quick_sort(v, start, j);
        quick_sort(v, j + 1, end);
    }

}

int main()
{
    vector<int> nums = {8, 6, 3, 2, 5, 4};
    vector<int> nums2 = {69, 2, 5, 30, 1, 0, 11, 3, 6, 9};
    int nums_size = nums.size();
    int nums2_size = nums2.size();

    quick_sort(nums, 0, nums_size);
    quick_sort(nums2, 0, nums2_size);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto &&i : nums2)
    {
        cout << i << " ";
    }
    

}