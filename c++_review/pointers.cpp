#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    // main memory is seperated into:
        //stack
        //heap
        //code
    // pointers can access data in heap
    int a = 10;
    int *ptr = &a;
    cout << ptr << endl; // prints address of a
    cout << *ptr << endl; // prints value of a - dereferencing

    int nums[3] = {1,2,3};
    int *p = nums; // for arrays, & isnt needed. the name of the array is the starting address

    cout << *p << endl; // prints nums[0]
    cout << p[0] << endl; // prints nums[0] - acts like array name
    cout << p << endl; // prints address of nums[0]

    int *b = new int[5]; // creates array in heap. b wil act as array name
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;
    b[4] = 5;

    cout << b << endl;
    delete [] b; //deletes the allocated memory



}