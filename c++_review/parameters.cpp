#include <iostream>
#include <array>
#include <string>

using namespace std;

//passing by address
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};

//pass by reference
void swap_2(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
};

int main()
{
    int a = 10, b = 5;
    int *a_ptr = &a;
    int *b_ptr = &b;
    int arr[] = {1,2,3};


    
    //calling by address. int *x = &a. swap dererefences it 
    swap(&a,&b);
    cout << a << endl << b << endl;

    //calling by reference
    swap_2(a,b);
    cout << a << endl << b << endl;



}