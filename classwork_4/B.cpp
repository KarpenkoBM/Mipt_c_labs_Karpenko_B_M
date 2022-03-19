#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout <<"Enter number of elements: ";
    cin >> n;
    int arr[n] ={0};
    cout <<"Enter elements of your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for ( int *arr_ptr = &arr[0]; arr_ptr <= &arr[n - 1]; *arr_ptr++)
    {
        cout << *arr_ptr<<' ';
    }
    cout << endl;
    for (int *arr_ptr = &arr[n - 1]; arr_ptr >= &arr[0]; *arr_ptr--)
    {
        cout <<*arr_ptr<<' ';
    }
    return 0;
}
