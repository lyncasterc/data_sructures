#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

//merging - combining two sorted lists into one sorted list
// O(m+n), m = list1 size, n = list2 size

vector<int> merge(vector<int> v1, vector<int> v2)
{
    vector<int> merged_vector;
    int v1_size = v1.size(), v2_size = v2.size();
    int i, j;
    i = j = 0;

    while(i < v1_size && j < v2_size)
    {
        if(v1[i] < v2[j])
        {
            merged_vector.push_back(v1[i++]);
        }
        else if (v1[i] > v2[j])
        {
            merged_vector.push_back(v2[j++]);
        }
    }

    while(i < v1_size)
    { merged_vector.push_back(v1[i++]); }

    while(j < v2_size)
    { merged_vector.push_back(v2[j++]); }

    return merged_vector;

}

int main()
{
    vector<int> nums = {2, 10, 18, 20, 23};
    vector<int> nums2 = {4, 9, 19, 25};
    vector<int> merged_nums = merge(nums, nums2);

    for (auto &&i : merged_nums)
    {
        cout << i << " ";
    }
    
    
}