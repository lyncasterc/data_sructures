#include <string>
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string name = "John";
    char name2[] = "John";

    for (size_t i = 0; i < 10; i++)
    {
        if (name[i] == '\0')
        {
            cout << i;
            break;
            
        }
        
    }
    
}