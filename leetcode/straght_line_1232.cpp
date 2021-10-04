#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() == 2)
        {
            return true;
        }
        
        double prev_slope, curr_slope, x1, y1, x2, y2;
        x1 = coordinates[0][0];
        y1 = coordinates[0][1]; 
        x2 = coordinates[1][0];
        y2 = coordinates[1][1]; 
        
        if(x1 == x2) 
        {
            prev_slope = -30000;
        } 
            
        else     
        {
            prev_slope = (y2 - y1) / (x2 - x1);
        }
        
        for(int i = 1; i < coordinates.size() - 1; i++)
        {
            x1 = coordinates[i][0];
            y1 = coordinates[i][1];
            x2 = coordinates[i + 1][0];
            y2 = coordinates[i + 1][1];
            
            if(x1 == x2)
            {
                curr_slope = -30000;  
            }
            
            else 
            {
                curr_slope = (y2 - y1) / (x2 - x1);     
            }
            
            if(curr_slope != prev_slope)
            {
                return false;
            }
        }
        
        return true;
    }

int main()
{
    vector<vector<int>> coors = {{0,0},{0,5},{5,5},{5,0}};
    cout << checkStraightLine(coors);
    


}
