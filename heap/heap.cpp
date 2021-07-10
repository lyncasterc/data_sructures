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
            auto i = heap.size();
            heap.emplace_back(key);

            while(i > 0 && key > heap[ i % 2 == 0 ? (i/2)-1 : (i/2)] )
            {
                heap[i] = heap[ i % 2 == 0 ? (i/2)-1 : (i/2)];
                i = i % 2 == 0 ? (i/2)-1 : (i/2);
            }
            heap[i] = key;
        }

        void create_heap(int a[], int n)
        {
            for (int i = 0; i < n; i++)
            {
                insert(a[i]);
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
    int arr[] = {20,40,10,3,50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    h.create_heap(arr, arr_size);

    

    h.display();

};