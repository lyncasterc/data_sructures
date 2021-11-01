#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::pair<int, int> a;
    std::pair<int, int> b={0,2};

    a= {0,2};
    bool result = a == b;

    auto it = a.first;


    std::cout << it;
    
    
}
