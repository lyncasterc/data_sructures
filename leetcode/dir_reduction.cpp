#include <vector>
#include <string>
#include <iostream>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};

bool isNegatable(std::vector< std::string>::iterator i){
    bool result;

    switch ((*i)[0]){
        case 'N':
            result = (*(i + 1))[0] == 'S';
            break;
        
        case 'S':
            result = (*(i + 1))[0] == 'N';
            break;
    
        case 'W':
            result = (*(i + 1))[0] == 'E';
            break;
    
        case 'E':
            result = (*(i + 1))[0] == 'W';
            break;  
    }
  
    return result;
}

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr){

    if (arr.size() <= 1){
        return arr;
    }
    
    bool removal_in_pass = true;
    
    while(removal_in_pass){
        
        removal_in_pass = false;
        
        for(auto i = arr.begin(); i != arr.end();){
        
        if(isNegatable(i)){
            arr.erase(i, i + 2);
            removal_in_pass = true; 
        }
        
        else
        {
            i++;
        }
        
        }  
    }

    return arr;
}

void print(std::vector<std::string> &arr)
{
    for (auto &&i : arr)
    {
        std::cout << i << " ";
    }   
}

int main()
{
    DirReduction r;
    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> d2 = {"NORTH", "SOUTH", "EAST", "WEST"};

 
    r.dirReduc(d2);

    print(d2);

}
