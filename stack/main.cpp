#include <array>
#include <iostream>
#include "ArrayStack.h"

using namespace std;


int main()
{
    ArrayStack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.display();

    cout << s.stack_top() << endl;
    
    
    
    
}