#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>


using namespace std;

void perm(string str, int k)
{
    static int A[10] = {0};
    static char result[10];
    int i;

    if(str[k] == '\0')
    {
        result[k] = '\0';
        cout << result << endl;
    }
    else
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if(A[i] == 0)
            {
                result[k] = str[i];
                A[i] = 1;
                perm(str, k + 1);
                A[i] = 0;
            }
        }
        
    }
}


int main()
{
    perm("ABC", 0);
}