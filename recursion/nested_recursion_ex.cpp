#include <iostream>
#include <array>
#include <string>

using namespace std;

// will always return 91 regardless of n.
int func(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return func(func(n+11));
    }
};

int main()
{
    int x = func(99);
    cout << x << endl;
}