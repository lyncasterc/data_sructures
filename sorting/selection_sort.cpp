#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void selection_sort(vector<int> &v)
{
    int size = v.size(), j, k, temp;

    for (int i = 0; i < size; i++)
    {
        j = k = i;

        // this loop makes more sense as a for loop because 
        // j is going up by one no matter what
        while(j < size - 1 )
        {   
            j += 1;
        
            if(v[j] < v[k])
            { k = j; }
        }

        temp = v[i];
        v[i] = v[k];
        v[k] = temp;
    }
    
}

int main()
{   
    vector<int> nums = {8, 6, 3, 2, 5, 4};
    vector<int> nums2 = {69, 2, 5, 30, 1, 0, 11, 3, 6, 9};
    selection_sort(nums);
    selection_sort(nums2);

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