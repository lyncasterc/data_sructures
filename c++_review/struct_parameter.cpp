#include <iostream>
#include <array>
#include <string>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

struct Test
{
    int arr[5];
    int n;
};

//passing by value
int area(Rectangle r)
{
    return r.length * r.width;
};

// passing by address
void double_length(Rectangle *r)
{
    r->length *=2;
};

// passing by reference 
void double_width(Rectangle &r)
{
    r.width *=2;
};

void print_test_arr(Test t)
{
    for (size_t i = 0; i < t.n; i++)
    {
        cout << t.arr[i] << " ";
    }
    cout << endl;
}


void double_test_arr(Test t)
{
    for (size_t i = 0; i < t.n; i++)
    {
        t.arr[i] *= 2;
    }
}




int main()
{
    Rectangle r1 = {2,5};
    Test t = {{2,4,6,8,10}, 5};

    //calling by value
    cout << "Area: " << area(r1) << endl;
    
    //calling by address

    double_length(&r1);
    cout << "Length: " << r1.length << endl;

    //passing by reference

    double_width(r1);
    cout << "width: " << r1.width << endl;

    //if a struct has an array, it can be passed by value. changes in function will not change struct in main
    print_test_arr(t);
    double_test_arr(t);
    print_test_arr(t);

}