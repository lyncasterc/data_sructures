#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;

class Hash
{
    private:
        int hash_arr[10];
        int hash_function(int val)
        {
            return val % 10;
        }
        int hash_function2(int val)
        {
            return 7 - (val % 7);
        }
        int double_hash_probe(int val)
        {
            int index = hash_function(val);
            int i = 0;

            while(hash_arr[(hash_function(val) + i * hash_function2(val)) % 10] && i < 10)
            { i++; }

            return (i >= 10) ? -1 : (hash_function(val) + i * hash_function2(val)) % 10;

        }
    
    public:
        Hash()
        {
            std::fill(std::begin(hash_arr), std::end(hash_arr), -1);
        }

        void insert(int val)
        {
            int index = hash_function(val);

            if(hash_arr[index] != -1)
            {
                index = double_hash_probe(val);
            }

            hash_arr[index] = val;
        }

        //TODO: write search, write get 


};

int main()
{

}