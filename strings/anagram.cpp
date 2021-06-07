#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;


bool includes(string str, char a)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if(a == str[i])
        { return true; }
    }
    return false;
};



bool is_anagram(string str, string str2)
{
    if(str.length() != str2.length())
    { return false; }

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if(!includes(str2, str[i]))
        { return false; }
    }

    return true;
    
};



int main()
{
    string name = "stiven";
    string name2 = "nevits";
    string name3 = "emilia";

    cout << is_anagram("ban", "nabl") << endl;

}