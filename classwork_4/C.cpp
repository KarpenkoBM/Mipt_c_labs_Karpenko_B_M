#include <iostream>
using namespace std;
static int static_counter()
{
    static int stat = 0;
    stat++;
    return stat;
}

int main()
{
    int p = 0;
    for (int n = 0; n < 10; n++)
    {
        p = static_counter();
    }
    cout << p;
    return 0;
}
