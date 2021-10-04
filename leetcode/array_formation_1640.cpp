#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) 
{
    int j, k;

    // looping through the pieces
    for(int i = 0; i < pieces.size(); i++)
    {
        // finding if the first int in pieces component is in arr
        auto it = std::find(arr.begin(), arr.end(), pieces[i][0]);
        
        // if it's not in arr, return false
        if(it == arr.end())
        {
            return false;
        }

        // if the pieces component has more than one number,
        // we must check if the order of the numbers in pieces component
        // is preserved in arr. The order within pieces component can not  change.
        if(pieces[i].size() > 1)
        {
            // finding the position of the first pieces component number in arr.
            j = std::distance(arr.begin(), it);
            k = 0; // for looping in pieces component

            // looping through pieces component
            while(++k < pieces[i].size() )
            {
                ++j;
                // if end of arr is reached while there are still more
                // numbers remanining in pieces component, return false
                    // because either the next number in pieces component does not exist or is out of order.
                    //ex: arr = [1,2,3], pieces[i] = [3,2] => false
                if(j >= arr.size() && k < pieces[i].size()){
                    return false;
                }
                //other wise, the if two numbers are not identical, return false
                    //ex: arr = [1,2,3,5], pieces[i] = [3,4] => false

                else if(arr[j] != pieces[i][k]){
                    return false;
                }

            }
        }
    }
    return true;
};


int main()
{
    vector<int>arr = {91, 4, 64, 78};
    vector<vector<int>> pieces = {{78}, {4, 64}, {91}};
    bool result = canFormArray(arr, pieces);

    std::cout << result << std::endl;
}