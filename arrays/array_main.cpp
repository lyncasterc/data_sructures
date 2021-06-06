#include <string>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Array.h"
#include <vector>

using namespace std;

int main()
{
    int a[] = {1,2,3};
    int a2[] = {4,5,6,7,8};
    Array<int> arr(a, 3, 10);
    Array<int> arr2(a2, 5, 10);


    int len = arr.get_length();
    int size = arr.get_size();


    arr.print();
    arr.rotate(3);
    arr.print();
    cout << "length: " << len << endl << "Size: " << size << endl; 
    


    


    


}