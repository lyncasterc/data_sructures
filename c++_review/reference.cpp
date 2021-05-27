#include <iostream>
#include <array>
#include <string>

using namespace std;



int main()
{
    int num = 10;
    int &r = num; // r becomes a reference to num. changes made to r also happen to num. num == r

    cout << r << endl;
    r--;
    cout << r << endl;
    cout << num << endl;

    cout << &r << endl;
    cout << &num << endl; // same addresses

    


}