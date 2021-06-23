#include <iostream>
#include <array>
#include "ArrayQueue.h"
#include "ListQueue.h"

using namespace std;

int main()
{
    ArrayQueue q(10);
    ListQueue q2;

    
    q2.enqueue(5);
    q2.enqueue(6);
    q2.enqueue(7);

    q2.display();


}