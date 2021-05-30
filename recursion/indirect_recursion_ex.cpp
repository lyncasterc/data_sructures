#include <iostream>
#include <array>
#include <string>

using namespace std;

void func_b(int n);

void func_a(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        func_b(n-1);
    }
    
};
void func_b(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        func_a(n/2);
    }
    
};

int main()
{
    func_a(3);

}