# include <iostream>

using namespace std;
int main()
{
    int i, number = 0;
    cin >> number;
    for (i = number - 1;i > 1; i-- )
    {
        if (number % i == 0)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
