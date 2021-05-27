#include <iostream>
#include <array>
#include <string>

using namespace std;

class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle()
        {length = width = 1;}

        Rectangle(int l, int w)
        {
            length = l;
            width = w;
        }

        int area()
        {
            return length * width;
        }

        void set_length(int l)
        {
            length = l;
        }

        ~Rectangle();
};


int main()
{
    Rectangle r(10,5);
    Rectangle r2;

    r.area();
    r.set_length(20);

}