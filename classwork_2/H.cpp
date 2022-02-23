# include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int number, reversed_number = 0, n;
    cin >> n >> number;
    auto saved_number = number;
    cout << number << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << number;
        reversed_number += (number % 10)*pow(10,n - i);
        number /= 10;
        cout << number << endl<<reversed_number<<endl;
    }
    if (reversed_number == saved_number)
    {
        cout << 1;
        return 0;
    }
    else
    {
        cout << reversed_number;
    }
    return 0;
}
