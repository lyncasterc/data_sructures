#include <array>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "CircLinkedList.h"

using namespace std;


int main()
{
    int arr[] = {1,2,3,4,5,6};
    int arr2[] = {4,3,2};

    LinkedList list(arr, 6);

    CircLinkedList circ_list(arr,6);

    circ_list.display();
    
    
    
    
}