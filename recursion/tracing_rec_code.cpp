#include <iostream>
#include <array>
#include <string>

using namespace std;

// uses recursion to count down from n
void count_down(int n)
{
    if (n > 0) // base case - function will stop calling itself when n is 0
    {
        cout << n << " ";
        count_down(n-1);
    }
    else
    {
        cout << endl;
    }
    
};

// uses recursion to count up to n
void count_up(int n)
{
    if (n > 0) // base case - function will stop calling itself when n is 0
    {
        count_up(n-1);
        cout << n << " ";
    }
    
};

int main()
{
    // count_down(20);
    count_up(3);
}