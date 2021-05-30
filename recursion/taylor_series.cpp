#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;


//returns taylor series of e^x, up to n terms
double e_taylor(int x, int n)
{
    static double p = 1;
    static double f = 1;
    double r;
    // base case/solution is 0 is passed in for x
    if(n == 0 || x == 0) 
    {return 1;}
    
    r = e_taylor(x, n - 1);
    p *= x;
    f *= n;
    return p/f + r;

};

int main()
{
    cout << e_taylor(1,10) << endl;
    cout << e_taylor2(1,10) << endl;
}