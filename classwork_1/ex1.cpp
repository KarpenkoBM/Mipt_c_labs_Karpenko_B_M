# include <iostream>
# include <cmath>
using namespace std;
int main ()
{
    int a, b;
    cin >> a >> b;
    auto d = sqrt(a*a + b*b);
    cout << "d = " << d;
    return 0;
}
