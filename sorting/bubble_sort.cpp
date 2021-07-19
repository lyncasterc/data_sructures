#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// each pass sorts the larger elements of the array,
// so in inner loop, you dont have to check the lower half of the array, 
// hence, the j < n - 1 - i condition in the inner loop.

// in bubble sort, one pass will give you largest element in the vector at the end
// n swaps, n greatest elements starting from the end.
// requires n-1 passes (outer loop)


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
};

// making bubble sort adaptive
// add a flag initilized to false
// if a swap is performed, set the flag to true
// out of the inner loop, if the flag is false, break

void adaptive_bubble_sort(vector<int> &v)
{
    int n = v.size();
    bool flag = false;
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
                flag = true;
            }
            else
            {
                continue;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {8, 5, 7, 3 ,2};
    vector<int> nums2 = {6, 4, 3, 1, 2};
    bubble_sort(nums);
    adaptive_bubble_sort(nums2);

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
