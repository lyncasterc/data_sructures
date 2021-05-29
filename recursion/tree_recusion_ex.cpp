#include <iostream>
#include <array>
#include <string>

using namespace std;


void func(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        func(n-1);
        func(n-1);
    }
    
}

int main()
{
    func(3);
}