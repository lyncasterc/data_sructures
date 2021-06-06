
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //sorted - hash method
    int a[] = {3,6,8,8,10,12,15,15,15,20};

    int hash[20] = {0};

    for (size_t i = 0; i < 10; i++)
    {
        hash[a[i]]++;
    }

    for (size_t i = 0; i < 20; i++)
    {
        if(hash[i] > 1)
        {
            // cout << i << " appeared " << hash[i] << " times" << endl << endl;
        }
    }
    

    //unsorted

    int a2[] = {8,3,6,4,6,5,6,8,2,7};
    int prev_dup;

    for (size_t i = 0; i < 9; i++)
    {
        int count = 1;

        for (size_t j = i + 1; j < 10; j++)
        {
            if (a2[i] == a2[j] && a2[i] !=  prev_dup)
            {
                count++;
            }
            
        }
        
        if(count > 1)
        {
            prev_dup = a2[i];

            cout << a2[i] << " appeared " << count << " times." << endl << endl;
        }
        
    }
    

    



    


    


}

