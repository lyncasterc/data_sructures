#ifndef LowerTriangularMatrix_H
#define LowerTriangularMatrix_H

#include <string>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class LowerTriangularMatrix
{
    private:
        int n;
        int *arr;
    public:
        LowerTriangularMatrix(int n)
        {
            this->n = n;
            arr = new int[n*(n+1)/2];
        };

        void set(int i, int j, int val)
        {
            if ( i >= j)
            { arr[i*(i-1)/2+j-1] = val; }
        };

        int get(int i, int j)
        {
            if ( i >= j)
            { return arr[i*(i-1)/2+j-1]; }
        };

        void display()
        {
            for (size_t i = 1; i <= n; i++)
            {
                for (size_t j = 1; j <= n; j++)
                {
                    if (i >= j)
                    {
                        cout << arr[i*(i-1)/2+j-1] << " ";
                    }
                    else
                    { cout << 0 << " ";}
                    
                }
                cout << endl; 
            }
            
        }

        ~LowerTriangularMatrix()
        { delete []arr; }
};

#endif