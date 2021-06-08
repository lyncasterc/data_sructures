#ifndef DiagonalMatrix_H
#define DiagonalMatrix_H

#include <string>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class DiagonalMatrix
{
    private:
        int n;
        int *arr;

    public:
        DiagonalMatrix(int n)
        {
            this->n = n;
            arr = new int[n];
        }

        void set(int row, int col, int val)
        {
            if(row == col)
            { arr[row - 1] = val; }
        };

        int get(int row, int col)
        {
            if(row == col)
            { return arr[row - 1]; }
        };
    
        void display()
        {
            for (size_t row = 0; row < n; row++)
            {
                for (size_t col = 0; col < n; col++)
                {
                    if(row == col)
                    {cout << arr[row] << " ";}
                    else
                    { cout << 0 << " ";}
                }
                cout << endl;
            }
            
        };
        

    ~DiagonalMatrix()
    {
        delete []arr;
    }
};

#endif