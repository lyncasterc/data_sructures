#include <iostream>
#include <vector>
#include <array>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{
    std::vector<int> result;
    int n = snail_map.size(); 
    int tl_coor[2] = {0, 0}; // top-left coor of the square (row, col)

    while(n > 0)
    {
        // top-left, going right
        for (int i = tl_coor[1]; i <= tl_coor[1] + n - 1; i++)
        {
            result.push_back(snail_map[tl_coor[0]][i]);
        }

        // top-right, going down
        for (int i = tl_coor[0] + 1; i <= tl_coor[0] + n - 1; i++)
        {
            result.push_back(snail_map[i][tl_coor[1] + n - 1]);
        }

        n--;
        tl_coor[0]++;

        // bottom-right, going left
        for (int i = tl_coor[1] + n - 1; i >= tl_coor[1]; i--)
        {
            result.push_back(snail_map[tl_coor[0] + n - 1][i]);
        }

        // bottom-left, going up
        for (int i = tl_coor[0] + n - 2; i >= tl_coor[0]; i--)
        {
            result.push_back(snail_map[i][tl_coor[1]]);
        }
        
        tl_coor[1]++;
        n--;

    }
    
    return result;

}



int main()
{
    std::vector<std::vector<int>> arr5 = {{3, 4, 7, 2, 1}, 
                                        {8, 6, 2, 0, 2},
                                        {9, 2, 11, 3, 3},
                                        {6, 1, 2, 5, 4},
                                        {9, 4, 1, 3, 5}};

    std::vector<std::vector<int>> arr4 = {{3, 4, 7, 2}, 
                                        {8, 6, 2, 0},
                                        {9, 2, 11, 3},
                                        {6, 1, 2, 5}};

    std::vector<std::vector<int>> arr3 = {{3, 4, 7}, 
                                        {8, 6, 2},
                                        {9, 2, 11}};

    std::vector<std::vector<int>> arr2 = {{3, 4}, 
                                        {8, 6}};

    std::vector<int> ans = snail(arr5);

    for (auto &&i : ans)
    {
        std::cout << i << " ";
    } 
    std::cout << std::endl;

    
}


