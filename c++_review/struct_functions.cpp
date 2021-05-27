#include <iostream>
#include <array>
#include <string>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

void init_rect(Rectangle *r, int l, int w)
{
    r->length = l;
    r->width = w;

};

int area(Rectangle r)
{
    return r.length * r.width;
};

void set_length(Rectangle *r, int l)
{   
    r->length = l;
}


int main()
{
    Rectangle r;
    init_rect(&r,10,5);
    area(r);
    set_length(&r, 20);

    

}