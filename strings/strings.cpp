#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

//returns length of string
int len(string str)
{
    int i;
    for ( i = 0; str[i] != '\0'; i++);
    return i;

};

void to_lower(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
};

void to_upper(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
};

void to_lower2(string &str)
{
    for (size_t i = 0; str[i]!= '\0'; i++)
    {
        if(str[i] >= 65 && str[i] <= 90 )
        {
            str[i] += 32;
        }
    }
    
};

void to_upper2(string &str)
{
    for (size_t i = 0; str[i]!= '\0'; i++)
    {
        if(str[i] >= 97 && str[i] <= 122 )
        {
            str[i] -= 32;
        } 
    }
};

int count_words(string str)
{
    int words = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            words++;
        }
        
    }
    words++;
    return words;
    
};

bool is_valid(string str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && !isspace(str[i]))
        {
            return false;
        }
        
    }
    return true;
    
};


int main()
{
    string name = "John";
    char name2[] = "John";

    //length of string
    cout << len(name2) << endl;
    cout << len(name) << endl;
    cout << name.length() << endl; //built in function for string type

    to_lower(name);
    cout << name << endl;

    to_upper(name);
    cout << name << endl;

    string name3 = "Silly";
    string name4 = "bIlly";

    //ascii code - add 32 to uppercase to make lower and vice-versa

    to_lower2(name3);
    to_upper2(name4);

    cout << name3 << endl << name4 << endl;

    //count num of words in string

    string hi = "Hello World!";

    cout << count_words(hi) << endl;


    //validating a string, characters/numbers and spaces  only

    string password = "123 cats";
    cout << is_valid(password) << endl;

    //reversing a string

    reverse(password.begin(), password.end());
    cout << password << endl;;

    


    
    
}