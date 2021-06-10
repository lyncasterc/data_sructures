#include <array>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;


int main()
{
    int arr[] = {1,2,3,4,5,6};
    LinkedList list(arr, 6);
    LinkedList list2;
    list2.initialize(arr,6);

    list.display();
    list2.display();
}