#include <array>
#include <iostream>
#include <string>
#include <ctype.h>
#include "ListStack.h"

using namespace std;

bool is_operator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    { return true; }

    return false;
}

int do_operation(char op, int a, int b)
{
    int result;

    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }

    return result;
}

//single digits only
int solution(string str)
{
    ListStack stack;
    int result, a, b;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if(!is_operator(str[i]))
        { stack.push(str[i] - '0'); }

        else 
        {
            b = stack.pop();
            a = stack.pop();

            result = do_operation(str[i], a, b);

            stack.push(result);

        }
    }
    
    result = stack.pop();

    return result;
}

int main()
{
    string str = "35*62/+4-";
    char a = '5';

    int result = solution(str);

    cout << result << endl;

}
