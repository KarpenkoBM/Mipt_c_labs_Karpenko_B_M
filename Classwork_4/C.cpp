#include <iostream>
using namespace std;
int statik_counter()
{
    static int statik = 0;
    statik++;
    return statik;
}
int main()
{
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        n = statik_counter();
    }
    cout << n;
    return 0;
}


