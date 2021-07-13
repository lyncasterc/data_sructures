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

        void create_heap(int arr[], int size)
        {
            for (int i = 0; i < size; i++)
            { 
                insert(arr[i]);
            }
            
        }

        void arr_swap(int arr[], int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;            
        }

        void max_heapify(int arr[], int size)
        {
            for (int i = ( size / 2) - 1; i >= 0; i--)
            {
                int j = 2 * i + 1; //left child

                while(j < size - 1)
                {
                    if(arr[j] < arr[j + 1]) //comparing left child and right child
                    { j = j + 1; }


                    if(arr[j] > arr[i])
                    {
                        arr_swap(arr, i, j);
                        i = j;
                        j = 2 * i + 1;
                    }

                    else
                    { break; }

                }
            }

        };

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

    MaxHeap h;
    int arr[] = {5,10,30,20,35,40,15};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    h.max_heapify(arr, arr_size);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    
};