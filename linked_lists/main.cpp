#include <array>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;


int main()
{
    int arr[] = {1,2,3,4,5,6};
    int arr2[] = {4,3,2};

    LinkedList list(arr, 6);
    LinkedList list2;

    list2.initialize(arr2,3);

    list.display();
    list2.display();

    cout << list.sum() << endl;
    cout << list2.sum() << endl;
}