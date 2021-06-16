#include <array>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "CircLinkedList.h"
#include "DoubleLinkedList.h"

using namespace std;


int main()
{
    int arr[] = {1,2,3,4,5,6};

    DoubleLinkedList list(arr,6);

    list.insert_at(2, 69);
    list.display();
    
    cout << list.tail()->value << endl;
    




    
    





    
    
    
    
}