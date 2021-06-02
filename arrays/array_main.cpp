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

// prints contents of array
void print_arr(Array arr)
{
    for (size_t i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
};

// pushes element end of array
void push(Array *arr, int val)
{
    arr->A[arr->length] = val; 
    arr->length++;
}

// inserts element at given index of array 
void insert(Array *arr, int index, int val)
{

    if (index >= 0 && index <= arr->length && arr->length < arr->size) 
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
    
};

// deletes element at given index of array, returns deleted element
int remove_element(Array *arr,int index)
{
    int element = arr->A[index];
    if(index <= arr->length && index >= 0)
    {
        for (size_t i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i+1]; 

        }

        arr->length--;
    }
    return element;
    
};

// returns index of key if found, or returns -1 if element not found
int linear_search(Array arr, int key)
{
    for (size_t i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
        
    }

    return -1;
};

// returns index of key in sorted array or -1 if not found
int binary_search(Array arr, int key, int first = -1, int last = -1)
{   
    if(first == -1)
    { first = 0; }

    if(last == -1)
    { last = arr.length - 1; }

    int middle = (last + first) / 2;

    if(arr.A[middle] == key )
    { return middle; }
;
    if (arr.A[middle]!= key && first == last)
    { return -1; }
    
    if(key < arr.A[middle])
    { return binary_search(arr, key, first, last = middle - 1); }

    else if (key > arr.A[middle])
    { return binary_search(arr, key, first = middle + 1 ,last); }
    
};

int main()
{
    
    Array arr = {{2,5,8,11,16,20,31,70}, 10, 8};

    // print_arr(arr);

    cout << linear_search(arr, 20) << endl;
    cout << binary_search(arr, 20) << endl;


}