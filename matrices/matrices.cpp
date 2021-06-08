#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"

using namespace std;

int main()
{
    DiagonalMatrix boop(5);
    boop.set(1,1,3);
    boop.set(2,2,7);
    boop.set(3,3,4);
    boop.set(4,4,9);
    boop.set(5,5,6);

    boop.display();


};