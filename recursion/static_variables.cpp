#include <iostream>
#include <array>
#include <string>

using namespace std;


void static_demo()
{
	// static variable
    static int count = 0; // the variable's value is rembererd each function call
	cout << count << " ";
	
	// value is updated and
	// will be carried to next
	// function calls
	count++;
};

// recursive function that returns the sum of all numbers from 0 up to n.
int sum_up_to(int n)
{
    if(n == 0) // base case
    {return 0;} 

    return sum_up_to(n-1) + n;
};

//returns n^2
int func(int n) 
{
    static int x = 0; // x allocated in memory and doesnt change each funcion call
    
    if(n == 0) // base case
    {return 0;} 

    x++;
    return func(n-1) + x;
};




int main()
{

    int x = 5;
    int y = sum_up_to(x);

    cout << y << endl;

    int a = func(9); 
    //func is called three times, which means x = 3 at the end. 
    // when the func calls are popped off when base case is met, x is still 3 the whole time. it doesnt go back to 2 or 1.
    // x is static, and is only created once in memory, and it's state is remebered no matter what.

    cout << a << endl;

    
    

}