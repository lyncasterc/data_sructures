#include <iostream>
#include <array>
#include <string>

using namespace std;

void print_arr(int x[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    
};

void double_arr(int x[], int size)
{
    {
    for (size_t i = 0; i < size; i++)
    {
        x[i] *= 2;
    }
}
};

int * create_arr(int n)
{
    int *p;
    p = new int[n];
    return p;
};


int main()
{
    int arr[5] = {2,4,6,8,10};
    int *a  = create_arr(5);
    a[0] = 25;
    cout << a[0];

    // arrays are passed by address to functions with arr parameters.
    // so technically, what's happening is: int *x = arr;
    print_arr(arr, 5);
    
    // therefore, any changes made to arrays in functions will be reflected in the actual arraay in main.
    double_arr(arr,5);
    print_arr(arr, 5);

}