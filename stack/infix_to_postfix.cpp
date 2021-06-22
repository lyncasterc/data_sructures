#include <array>
#include <iostream>
#include <string>
#include <ctype.h>
#include "ArrayStack.h"
#include "ListStack.h"

using namespace std;

bool is_num(int x)
{
    if( x >= 48 && x <= 57)
    { return true;}

    return false;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
    { return 1; }
    else if (x == '*' || x == '/')
    { return 2; }
    
    return 0;

}

string solution(string str)
{   
    ListStack stack;
    string postfix;
    int i = 0;
    
    while(str[i] != '\0')
    {
        if(isalnum(str[i]))
        { postfix.push_back(str[i++]); }

        else
        {
            if(precedence(str[i]) > precedence(stack.peek(1)))
            { stack.push(str[i++]); }

            else
            { postfix.push_back(stack.pop()); }
        }
    }

    while(!stack.is_empty())
    {
        postfix.push_back(stack.pop());
    }
    return postfix;
};

int main()
{
    string str = "25*5+2-10";
    ListStack stack;

    cout << solution(str) << endl;

}