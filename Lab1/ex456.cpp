#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
    while (a != b)
    {
    if (a>b)
    {
        a = a-b;
    }
    else
    {
        b = b - a;
    }

    }
    return a;
}

int scm(int a, int b)
{
    return ((a*b)/gcd(a,b));
}

int main()
{
    int a, b;
    cin >> a >> b;
    if  (a == 0 or b ==0)
    {
        cout <<"Error";
        return 0;
    }
    cout << "gcd = " << gcd(a,b) << " scm = " << scm(a,b);
    return 0;
}



