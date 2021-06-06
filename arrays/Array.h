#ifndef Array_H
#define Array_H

#include <string>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
template<class T>

class Array
{
    private:
        T *A; // will point to array
        int size; // size allocatedd for arr
        int length; // number of elements in arr

        //returns index of key if found, or -1 if not found
        int linear_search(T key)
        {
            for (size_t i = 0; i < length; i++)
            {
                if (A[i] == key)
                {
                    return i;
                }
                
            }
            return -1;
        };

    public:
        Array()
        {
            size = 20;
            A = new T[20];
            length = 0;
        };

        Array(T arr[], int len, int s)
        {
            size = s;
            length = len;
            A = new T[s];

            for (size_t i = 0; i < len; i++)
            {
                A[i] = arr[i];
            }

        };

        //prints contents of A
        void print()
        {
            for (size_t i = 0; i < length; i++)
            {
                cout << A[i] << " ";
            }
            
            cout << endl;
        }

        // sets the contents of A, changes length and size
        void set_array(T arr[], int len, int s = 20)
        {

            length = len;            

            if (s != 20)
            {
                size = s;
                resize_array(s);
            }
            
            for (size_t i = 0; i < len; i++)
            {
                A[i] = arr[i];
            }

        };
        
        //resizes A
        void resize_array(int s)
        {
            T *arr = new int[s];

            for (size_t i = 0; i < length; i++)
            {
                arr[i] = A[i];
            }

            delete []A;

            A = arr;
            arr = NULL;
            
        }
        
        //returns size
        int get_size()
        { return size; }

        //returns length
        int get_length()
        { return length; }

        //appends new element to end of A
        void push(T val)
        {
            A[length] = val;
            length++;
        };

        //insets new element at specific index of A
        void insert(int index, T val)
        {
            if (index >= 0 && index <= length && length < size)
            {
                for (size_t i = length; i >= index; i--)
                {
                    if (i == index)
                    {
                        A[index] = val;
                        length++;
                    }
                    else
                    {
                        A[i] = A[i-1];
                    }
                    
                }
                
            }
            
        };

        //removes element at specific index of A and returns it
        T remove(int index)
        {
            T val = A[index];

            if (index <= length && index >= 0)
            {
                for (size_t i = index; i < length - 1; i++)
                {
                    A[i] = A[i + 1];
                }
                
                length--;
            }
        
            return val;
        };

        //removes last element of A and returns it
        T pop()
        {
            return remove(length - 1);
        };
        
        //returns true if A is sorted, otherwise returns false
        bool is_sorted()
        {
            for (size_t i = 0; i < length - 1; i++)
            {
                if (A[i] > A[i + 1])
                {
                    return false;
                }
                
            }
            return true;
            
        }

        //returns index of key if found, or -1 if not found
        int find(T key)
        { return linear_search(key); };

        //returns element at A[index] or -1 if index is not valid
        T get(int index)
        {
            if (index >= 0 && index < length)
            {
                return A[index];
            }
            return -1;
        }

        //replaces element at A[index] with val.
        void replace(int index, T val)
        {
            if(index >=0 && index < length)
            {
                A[index] = val;
            }
        };

        //reverse elements in A
        void reverse()
        {
            int temp;
            for (size_t i = 0; i < length / 2; i++)
            {
                temp = A[length - i - 1];
                A[length - i - 1] = A[i];
                A[i] = temp;
            }
            
        }

        //removes first element in A
        void shift()
        { remove(0); };

        //rotates elements in A by the rotation factor, n
        //Positive values for n rotate to the right and vice-versa.
        void rotate(int n)
        {
            int arr2[length];

            for (size_t i = 0; i < length; i++)
            {
                arr2[(i + n) % length] = A[i];
            }
            
            set_array(arr2, length, size);
        };

        


        ~Array()
        {
            delete []A;
        };


};

#endif
