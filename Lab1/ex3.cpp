# include <iostream>

using namespace std;
int main()
{
    int n, p;
    cin >> n;
    if (n > 0)
    {
        p = 1;
    }
    else if (n == 0)
    {
        p = 0;
    }
    else if (n < 0)
    {
        cout <<"Error";
        return 0;
    }
    while (n != 0)
    {
        p = p*n;
        n--;
    }
    cout << p;
    return 0;
}
