#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;

class Hash
{
    private:
        int hash_arr[10] = {-1};

        int hash_function(int val)
        {
            return val % 10;
        }
        int probe(int val)
        {
            int index = hash_function(val);
            int i = 0;

            while(hash_arr[(index + i) % 10] != -1)
            { i++; }

            return (index + i) % 10;
        }
    
    public:
        Hash()
        {
            std::fill(std::begin(hash_arr), std::end(hash_arr), -1);
        }

        void insert(int val)
        {
            int index = hash_function(val);

            // collision
            if(hash_arr[index] != -1)
            {
                index = probe(val);
            }
            hash_arr[index] = val;
        }

        int search(int val)
        {
            int index = hash_function(val);
            int i = 0;

            while(hash_arr[(index + i) % 10] != val && i < 10)
            { i++; }

            return (i >= 10) ? -1 : (index + i) % 10;
        }

        int get(int index)
        {
            return hash_arr[index];
        }

};

int main()
{
    Hash h;
    h.insert(12);
    h.insert(25);
    h.insert(35);
    h.insert(26);

    // cout << h.get(2) << endl; // 12
    // cout << h.get(5) << endl; // 25
    // cout << h.get(6) << endl; // 35
    // cout << h.get(7) << endl; // 26
    
    cout << h.search(27) << endl;

}