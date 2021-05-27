#include <iostream>
#include <array>
#include <string>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    Rectangle r1 = {10,5};
    Rectangle *rec_ptr = &r1;

    //accessing struct data  from pointer
    rec_ptr->length = 20;
    cout << rec_ptr->length << endl; 

    //creating dynamic struct in heap
    Rectangle *p;
    p = new Rectangle; // p is now a dyanmic structure in heap

    p->length = 5;
    p->width = 10;

    cout << p->length << endl;

    



}