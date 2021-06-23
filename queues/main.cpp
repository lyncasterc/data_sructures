#include <iostream>
#include <array>
#include "ArrayQueue.h"

using namespace std;

int main()
{
    ArrayQueue q(10);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.display();

    cout << q.first() <<endl;
    cout << q.last() <<endl;
}