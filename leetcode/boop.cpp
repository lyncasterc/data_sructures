#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


void print(std::vector<int> &arr)
{
    for (auto &&i : arr)
    {
        std::cout << i << " ";
    }   
}

bool isNegatable(std::vector<const int>::iterator i)
{
    return (*i + *(i + 1) == 0);
}


int main()
{
    std::vector<int> arr = {1, 2, -2, -1, -2, -2};
    int deleted = 1;

    while(deleted > 0)
    {
        deleted = 0;

        for (auto i = arr.cbegin(); i != arr.cend();)
        {
            if(isNegatable(i))
            {
                i = arr.erase(i, i + 2);
                deleted++;
            }
            else
            {
                i++;
            }
        }
    }


    std::vector<std::string> name = {"hi", "bye"};

    auto it = name.begin();

    std::cout << (*(it + 1))[0];
    

    

    // print(arr);
    
    
}
