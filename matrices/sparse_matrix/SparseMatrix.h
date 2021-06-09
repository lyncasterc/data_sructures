#ifndef SparseMatrix_H
#define SparseMatrix_H

#include <array>
#include <iostream>
#include <iomanip>
#include "Element.h"

using namespace std;

class SparseMatrix
{
    private:
        int rows;
        int cols;
        int non_zeros;
        Element *ele;
    public:
        SparseMatrix(int rows, int cols, int non_zeros)
        {
            this->rows = rows;
            this->cols = cols;
            this->non_zeros = non_zeros;
            ele = new Element[non_zeros];
        };

        friend istream &operator >>(istream &is, SparseMatrix &s);

        friend ostream &operator <<(ostream &os, SparseMatrix &s);

        SparseMatrix operator +(SparseMatrix &s)
        {
            int i,j,k;

            if(rows != s.rows || cols != s.cols)
            {
                //pass 
            }
            SparseMatrix *sum = new SparseMatrix(rows, cols, non_zeros + s.non_zeros);

            i = j = k = 0;

            while(i < non_zeros && j < s.non_zeros)
            {
                if(ele[i].row < s.ele[j].row)
                {
                    sum->ele[k++] = ele[i++];
                }
                else if (ele[i].row > s.ele[i].row)
                {
                    sum->ele[k++] = s.ele[j++];

                }
                else
                {
                    if(ele[i].col < s.ele[j].col)
                    {
                        sum->ele[k++] = ele[i++];
                    }

                    else if (ele[i].col > s.ele[j].col)
                    {
                        sum->ele[k++] = s.ele[j++];

                    }
                    else
                    {
                        sum->ele[k] = ele[i];
                        sum->ele[k++].val = ele[i++].val + s.ele[j++].val;
                        
                    }
                }
            }

            for(; i < non_zeros;i++)sum->ele[k++] = ele[i];
            for(; j < s.non_zeros;j++)sum->ele[k++] = ele[j];

            sum->non_zeros = k;
            return *sum;
        }

        ~SparseMatrix()
        { delete []ele; }
};

ostream &operator <<(ostream &os, SparseMatrix &s)
{
    int k=0;

    for (size_t i = 1; i <= s.rows; i++)
    {
        for (size_t j = 1; j <= s.cols; j++)
        {
            if(s.ele[k].row == i && s.ele[k].col == j)
            {
                cout << s.ele[k++].val << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return os;
};

istream &operator >>(istream &is, SparseMatrix &s)
{
    cout << "Enter the non-zero elements: " << endl;
    for (size_t i = 0; i < s.non_zeros; i++)
    {
        cout << "Row: ";
        cin >> s.ele[i].row;
        cout << endl; 

        cout << "Column: ";
        cin >> s.ele[i].col;
        cout << endl; 

        cout << "Value: ";
        cin >> s.ele[i].val;
        cout << endl; 
    
    }
    return is;
};


#endif