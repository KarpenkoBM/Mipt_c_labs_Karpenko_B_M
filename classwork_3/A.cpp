#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N] = {0};
    for (int p = 1; p <= N; p++)
    {
        cin >> arr[p];
    }
    int i = 1;
    int j = 2;
    while ( i <= N)
    {
        if (arr[i - 1] < arr[i])
        {
            i = j;
            j = j + 1;
        }
        else
        {
            swap(arr[i - 1],arr[i]);
            i = i - 1;
        }

        if (i == 0)
        {
            i = j;
                j = j + 1;
        }
    }
    for (int p = 1; p <= N; p++)
    {
        cout << arr[p]<< endl;
    }
return 0;
}
