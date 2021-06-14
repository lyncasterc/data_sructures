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
    int len = list.length();

    LinkedList list2;
    list2.initialize(arr2,3);

    list.display();
    cout << endl;
    list.reverse();
    list.display();

}