#include <iostream>
#include <array>
#include <string>

using namespace std;

int rec_factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return rec_factorial(n - 1) * n;
};

int main()
{
    cout << rec_factorial(4) << endl;
}