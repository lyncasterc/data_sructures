#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// inserting a new element into a sorted vector, at the right place

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

    insertion_sort(nums);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    
}