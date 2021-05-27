#include <iostream>
#include <array>
#include <string>

using namespace std;

struct Person
{   
    string name;
    int age;
    string profession;
};

struct ComplexNumber
{
    int a;
    int b;
};


struct Card
{
    string suit; // clubs, spades, diamonds, hearts
    char type; // 13 types, 2,3,4,5,6,7,8,9,10,q,k,j,a
};
    
int main()
{
    Person sc = {"Stiven Cabrera", 25, "Software Engineer"};

    cout << sc.age << endl;
    cout << sc.name << endl;
    cout << sc.profession << endl;

    cout << sizeof(sc) << endl;
    cout << sizeof(sc.name) << endl;
    
}