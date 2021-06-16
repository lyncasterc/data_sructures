#ifndef Node2_H
#define Node2_H

#include <array>
#include <iostream>

using namespace std;

class Node2
{
    public:
        int value = NAN;
        Node2 *prev_node = NULL;
        Node2 *next_node = NULL;
    
};

#endif