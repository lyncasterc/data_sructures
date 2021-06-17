#include <array>
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int arr_2[] = {30,8};

    LinkedList list(arr, 5);
    LinkedList list_2(arr_2, 2);
    list_2.tail()->next_node = list.at(-2);

    //solution

    for (size_t i = 0; i < list_2.length() - 1; i++)
    {
        if(list.find(list_2.at(i)->value))
        {
            cout << list_2.at(i)->value << endl;
            break;
        }
    }
    
}