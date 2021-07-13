#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class MaxHeap
{
    private:
        vector<int> heap;

    public:
        bool is_empty() const 
        { return heap.empty(); }

        int get_max() const
        { return heap[0]; }

        void insert(int key)
        {
            heap.emplace_back(key);
            auto i = heap.size() - 1;

            while(i > 0 && key > heap[(i - 1) / 2] )
            {
                heap[i] = heap[(i - 1) / 2];
                i = (i - 1) / 2;
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
            length = heap.size();
            heap[0] = heap.back();
            heap.pop_back();
            
            i = 0;
            j = i* 2 + 1;

            while (j < length - 1)
            {
                
                if(heap[j + 1] > heap[j])
                { j++; }

                if(heap[j] > heap[i])
                {
                    swap_keys(i, j);
                    i = j;
                    j = j* 2 + 1;
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