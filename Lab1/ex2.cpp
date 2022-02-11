#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    auto d = b*b - 4*a*c;
    if (a == 0)
    {
        auto x = (-c)/b;
        cout << "(Simple case) x = "<< x;
    }
    else
    {
        if (d < 0)
        {
            cout << "No real solutions";
        }
        else if (d = 0)
        {
            auto x = (-b)/(2*a);
            cout << "(Single solution) x = " << x;
        }
        else if (d > 0)
        {
            auto x1 = (-b - sqrt(d))/(2*a);
            auto x2 = (-b + sqrt(d))/(2*a);
            cout << "x1 = "<< x1<< " x2 = " << x2;
        }
    }

    return 0;
}
