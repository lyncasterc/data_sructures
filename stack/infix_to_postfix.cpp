#include <array>
#include <iostream>
#include <string>
#include <ctype.h>
#include "ListStack.h"

using namespace std;

//Solution 1:
// +,-,*,/
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

//Solution 2
// +,-,*,/,(,),^
int out_prec(char x)
{
    if(x == '+' || x == '-')
    { return 1; }
    else if(x == '*' || x == '/')
    { return 3; }
    else if(x == '^')
    { return 6; }
    else if(x == '(')
    { return 7; }
    else if(x == ')')
    { return 0; }
    return -1;  
};

int in_prec(char x)
{
    if(x == '+' || x == '-')
    { return 2; }
    else if(x == '*' || x == '/')
    { return 4; }
    else if(x == '^')
    { return 5; }
    else if(x == '(')
    { return 0; }
    return -1;  
};

string solution_2(string str)
{
    ListStack stack;
    string postfix;
    int i = 0;

    while (str[i] != '\0')
    {
        if(isalnum(str[i]))
        { postfix.push_back(str[i++]); }

        else
        {
            if(stack.is_empty() || out_prec(str[i]) > in_prec(stack.peek(1)))
            { stack.push(str[i++]); }

            else if(out_prec(str[i]) < in_prec(stack.peek(1)))
            { 
                postfix.push_back(stack.pop()); 
            }

            else
            {
                stack.pop();
            }
            
        }
    }
    
    while(!stack.is_empty() && stack.peek(1) != 41)
    { postfix.push_back(stack.pop()); }
    

    return postfix;
};

int main()
{
    string str = "25*5+2-10";
    string str_2 = "3*(4-2)+6";

    // cout << solution(str) << endl;
    cout << solution_2("1+3*(2*6)/2") << endl;

}