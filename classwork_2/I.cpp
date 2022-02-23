# include <iostream>

bool simple_dimple(int number)
{
    for (int i=2;i*i <= number; i++ )
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

using namespace std;
int main()
{
    int number;
    cout <<"Enter a number for factorisation: ";
    cin >> number;
    cout << "All simple multipliers: ";
    for (int i = 2;i <= number; i++ )
    {
        if (simple_dimple(i) and number % i == 0)
        {
            cout << i << ' ' ;
        }

    }
    return 0;
}
