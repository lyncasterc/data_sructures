#include <iostream>
#include <array>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
};

int P[10]; // memoization, using array to store values between function calls

int fibonacci2(int n)
{
    if(n == 0 || n == 1)
    {
        P[n] = n;
        return n;
    } 
    else
    {
        if (P[n-2] == -1)
        {
            P[n-2] = fibonacci2(n-2);
        }
        if (P[n-1] == -1)
        {
            P[n-1] = fibonacci2(n-1);
        }
        
        return P[n-1] + P[n-2];

    }
    
};


int main()
{
    fill_n(P, 10, -1);

    cout << fibonacci(3) << endl;
    cout << fibonacci2(3) << endl;
}