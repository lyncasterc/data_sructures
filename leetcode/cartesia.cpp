#include <vector>
#include <iostream>
#include <array>
#include <algorithm>




bool isValidWalk(std::vector<char> walk) {
    int minutes = walk.size();
    int start_pos[2] = {0, 0}; 
    
    if (minutes != 10) {
        return false;
    }
    
    for (auto &&i: walk) {
        switch(i){
            case 'n':
                start_pos[1]++;
                break;
            case 's':
                start_pos[1]--;
                break;
            case 'e':
                start_pos[0]++;
                break;
            case 'w':
                start_pos[0]--;
                break;    
        }
    }
    
    if (start_pos[0] != 0 || start_pos[1] != 0){
        return false;
    }
    
    return true;
};

int main()
{
    std::vector<char> path = {'e','w','e','w','n','s','n','s','e','w'};
    std::cout << isValidWalk(path) << std::endl;
}