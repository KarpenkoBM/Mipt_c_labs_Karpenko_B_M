#include <iostream>
using namespace std;
const int N = 10;
void gnomeSort (int (&arr)[N])
{
    int i = 1;
    int j = 2;
    while ( i < N)
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
}
int main(){

    int arr[N] = {0};
    cout << "Type an array with "<<N<<" numbers: ";
    for(int p = 0; p < N; p++)
    {
       cin >> arr[p];
    }
    gnomeSort(arr);
    int left = 0;
    int right = N - 1;
    int mid = 0;
    int number;
    cout <<"Type a number you need to find : ";
    cin >> number;
    for(int p = 0; p < N; p++)
    {
       cout <<"array["<<p<<"] : "<< arr[p]<<endl;
    }
    while (left < right)
    {
        mid = left + (right - left)/2;\
        if (arr[mid] == number)
        {
            cout <<"Your number is "<< mid<<" in sorted array";
            return 0;
        }
        else if (arr[mid] > number)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << "Error: there is no such number.";
return 0;
}














