#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned int year;
    cin >> year;
    if (year % 400 == 0 or year % 4 == 0 and year % 100 != 0)
    {
        cout <<"Yes";
    }
    else
    {
        cout <<"No";
    }
}
