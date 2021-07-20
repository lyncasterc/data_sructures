#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// worst case O(n^2), best case O(nlogn)
void quick_sort(vector<int> &v, int start, int end)
{
    if((end - start) > 1)
    {
        int pivot = v[start], i = start + 1, j = end - 1, temp;
        while(j >= i)
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
    vector<int> nums = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    vector<int> nums2 = {50, 70, 60, 90, 40, 80, 10, 20, 30};
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