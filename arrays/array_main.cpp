#include <string>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>
// #include "Array.h"

using namespace std;

struct Array
{
    int A[10]; // points to array in heap
    int size; //size of array
    int length; // # of elements in array

};

void print_arr(Array arr)
{
    for (size_t i = 0; i < arr.size; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
};

void push(Array *arr, int val)
{
    arr->A[arr->length] = val; 
    arr->length++;
}

void insert(Array *arr, int index, int val)
{

    if (arr->length < arr->size) 
    {
        for (size_t i = arr->length; i >= index; i--)
        {
            if (i == index)
            {
                arr->A[index] = val;
                arr->length++;
            }
            else
            {
                arr->A[i] = arr->A[i-1];
            }
        }
    }
    else
    {
        
    }


    

    
}



int main()
{
    Array arr = {{1,2,3}, 10, 3};
    push(&arr, 10);
    insert(&arr, 1, 69);
    print_arr(arr);
    





    
    

}