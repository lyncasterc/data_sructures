#include <iostream>
#include <array>
#include <string>

using namespace std;

template<class T>

class Arithmetic
{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a, T b)
        {
            this->a = a;
            this->b = b;
        }

        T add()
        {
            return a + b;
        }

        T subtract()
        {
            return a - b;
        }
};

int main()
{

    Arithmetic calc(5.5,2.9);
    Arithmetic calc2(5,2);

    cout << calc.add() << endl;
    cout << calc2.add() << endl;

    return 0; 
}