#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Heap
{
    private:
        vector<int> heap;
    public:
        void insert(int key)
        {
            heap.emplace_back(key);
            auto i = heap.size() - 1;

            while(i > 0 && key > heap[ i % 2 == 0 ? (i/2)-1 : (i/2) ] )
            {
                heap[i] = heap[ i % 2 == 0 ? (i/2)-1 : (i/2)];
                i = i % 2 == 0 ? (i/2)-1 : (i/2);
            }
            heap[i] = key;
        }

        void create_heap(int a[], int size)
        {
            for (int i = 0; i < size; i++)
            { 
                insert(a[i]);
            }
            
        }

        void swap_keys(int i, int j)
        {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        void delete_key()
        {
            int i, j, length;
            heap[0] = heap.back();
            heap.pop_back();
            length = heap.size() - 1;
            
        
            i = 0;
            j = 2 * i;

            while (j > length)
            {
                
                if(heap[j + 1] > heap[j])
                { j++; }

                if(heap[j] > heap[i])
                {
                    swap_keys(i, j);
                    i = j;
                    j *= 2;
                }
                else
                { break; }
            }

        }

        void display()
        {
            for (auto i : heap)
            {
                cout << i << " ";
            }
            
        }


};

int main()
{

    Heap h;
    int arr[] = {40, 35, 15, 30, 10, 12, 6, 5, 20};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    h.create_heap(arr, arr_size);

    h.display();

    // h.delete_key();
    // cout << endl;
    // h.display();

};