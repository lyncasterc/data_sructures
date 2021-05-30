#include <iostream>
#include <array>
#include <string>

using namespace std;

int rec_sum_up_to(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return rec_sum_up_to(n - 1) + n;
};

int loop_sum_up_to(int n)
{   
    int sum = 0;
    for (size_t i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;

};

int form_sum_up_to(int n)
{
    int sum = (n * n + n)/2;
    return sum;
};




int main()
{
    cout << rec_sum_up_to(3) << endl;
    cout << loop_sum_up_to(3) << endl;
    cout << form_sum_up_to(3) << endl;


    
    
}