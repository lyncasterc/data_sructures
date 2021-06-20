#include <array>
#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "ListStack.h"

using namespace std;

bool solution(string str)
{
    int open = 40;
    int close = 41;
    ListStack stack;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == open)
        { stack.push(open); }

        else if (str[i] == close)
        {
            if(stack.is_empty())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
    }
    
    if(!stack.is_empty())
    { return false; }

    return true;

};

int main()
{
    string str_1 = "((a+b)*(c-d))";
    string str_2 = "(((a+b)*(c-d))";
    string str_3 = "((a+b)*(c-d)))";

    cout << solution(str_3) << endl;

    

    

}