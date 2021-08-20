#include <vector>
#include <iostream>
#include <chrono>



using namespace std;

//O(N^2)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> solution = {};
    int length = nums.size();

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (nums[i] + nums[j] == target && i != j)
            {
                solution.push_back(i);
                solution.push_back(j);
                break;
            }
        }

        if (solution.size() >= 2)
        {
            break;
        }
    }

    return solution;
};

vector<int> twoSum2(vector<int> &nums, int target)
{
    vector<int> solution = {};
    int length = nums.size();
    int j = 0, i = length - 1;
    bool running = true;

    while (length> 0 || running)
    {
        if (nums[i] + nums[j] != target)
        {
            j++;
        }
        else if (nums[i] + nums[j] == target && i != j)
        {
            solution.push_back(j);
            solution.push_back(i);
            running = false;
            break;
        }
        if (j >= i)
        {
            nums.pop_back();
            length--;
            j = 0;
            i = length - 1;
        }
    }

    return solution;
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> solution = twoSum(nums, target);
    vector<int> solution2 = twoSum2(nums, target);

    for (auto &&i : solution2)
    {
        cout << i << " " << endl;
    }
}