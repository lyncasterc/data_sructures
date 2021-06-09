#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"
#include "./sparse_matrix/SparseMatrix.h"

using namespace std;

int main()
{
    DiagonalMatrix matrix(5);
    matrix.set(1,1,3);
    matrix.set(2,2,7);
    matrix.set(3,3,4);
    matrix.set(4,4,9);
    matrix.set(5,5,6);

    // matrix.display();

    SparseMatrix matrix2(4,5,5);
    cin >> matrix2;
    cout << matrix2;

};