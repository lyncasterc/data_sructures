#include <iostream>
#include <array>
#include <cmath>

using namespace std;


int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
};

int nCr(int n, int r)
{
    int a,b,c, result;
    a = factorial(n);
    b = factorial(r);
    c = factorial(n-r);

    result = a / (b * c);

    return result;
    
};

int rec_nCr(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    
    return rec_nCr(n-1, r-1) + rec_nCr(n-1, r);
};

int main()
{
    cout << nCr(5,2) << endl;
    cout << rec_nCr(5,2) << endl;

}