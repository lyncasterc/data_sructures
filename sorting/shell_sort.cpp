#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void shell_sort(vector<int> &v)
{
    int size = v.size(), temp, i, i2, j, k, gap;
    gap = size / 2;
    
    while(gap >= 1)
    {
        i = 0;
        j = i + gap;

        while(j < size)
        {
            temp = v[i];

            if(v[i] > v[j])
            {
                v[i] = v[j];
                v[j] = temp;
                k = i - gap;
                i2 = i;

                while(k >= 0)
                {
                    temp = v[k];
                    if (v[k] > v[i2])
                    {
                        v[k] = v[i2];
                        v[i2] = temp;
                        i2 = k;
                        k = i2 - gap;
                    }
                    else
                    {
                        i++;
                        j = i + gap;
                        break;
                    }
                }
            }
            else
            {
                i++;
                j = i + gap;
            }
        }
        
        gap /= 2;
    }
    

}


int main()
{
    vector<int> nums = {2, 4, 3, 5, 10, 6, 8, 16, 12, 13, 9};

    shell_sort(nums);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    

}