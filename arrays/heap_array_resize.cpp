#include <iostream>
#include <array>
#include <string>

using namespace std;

void print_arr(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
};



int main()
{
    

    //resizing an array created in heap memory

    int *p = new int[5];
    int x[5];
    p[0] = 1;
    p[1] = 5;

    int *q = new int[10]; // create new array in heap with larger size

    // copy contents of old array into new array
    for (size_t i = 0; i < 5; i++) 
    {
        q[i] = p[i]; 
    }

    delete [] p; // delete old array in heap;
    
    p = q; // point old array name to new array
    q = NULL; // new array name point to null. 

    print_arr(p, 10); // new larger array with old array data
}