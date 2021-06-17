#include <array>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "CircLinkedList.h"
#include "DoubleLinkedList.h"

using namespace std;


int main()
{
    int arr[] = {1,2,3,4,5};
    DoubleLinkedList list(arr,5);
    int len = list.length();

    list.display();
    cout << list.at(len / 2)->value << endl;
    
    




    
    





    
    
    
    
}