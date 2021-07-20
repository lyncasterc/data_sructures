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

void merge(vector<int> &v, int start, int mid, int end)
{
    int i = start, j = mid;
    vector<int> merged_vec;

    while(i < mid && j < end)
    {
        if(v[i] < v[j])
        {
            merged_vec.push_back(v[i++]);
        }
        else if(v[i] > v[j])
        {
            merged_vec.push_back(v[j++]);
        }
    }

    while(i < mid)
    { merged_vec.push_back(v[i++]); }

    while(j < end)
    { merged_vec.push_back(v[j++]); }

    for (auto i = start; i < end; i++)
    {
        v[i] = merged_vec[i];
    }

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
    

    vector<int> nums3 = {2, 5, 8, 12, 3, 6, 7, 10};
    int nums3_size = nums3.size();
    merge(nums3, 0, nums3_size / 2, nums3_size);

    cout << endl << endl;

    for (auto &&i : nums3)
    {
        cout << i << " ";
    }


    
}