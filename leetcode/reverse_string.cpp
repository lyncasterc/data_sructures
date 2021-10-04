#include <iostream>
#include <string>
#include <algorithm>


void reverse_string(std::string &str)
{
    int size = str.size(), i, j;
    i = 0;
    j = size - 1;

    while(i < j)
    {
        std::swap(str[i++], str[j--]);
    }

}

int main()
{  
    std::string str = "world";
    reverse_string(str);
    std::cout << str;
}
