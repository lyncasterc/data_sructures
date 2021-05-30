#include <iostream>
#include <array>
#include <string>

using namespace std;

//returns m^n
int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(m, n - 1) * m;
    
}

int main()
{
    cout << power(2,3) << endl;
}