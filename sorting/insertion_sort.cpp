#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// requires n-1 passes (outer loop)
// inserting a new element into a sorted vector, at the right place
// insertion sort is better in linked list because no swaps required.
// adaptive because it takes O(n) when vector is already sorted


void insertion_sort(vector<int> &v) 
{
    int size = v.size(), temp, j;

    for (int i = 1; i < size; i++)
    {
        temp = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
    }

}


int main()
{
    vector<int> nums = {8, 5, 7, 3, 2, 60, 20, 1, 0, 21};
    vector<int> nums2 = {1, 4, 5, 6, 10, 11};

    insertion_sort(nums);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }

}