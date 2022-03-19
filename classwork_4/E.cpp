#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << ' ';
}
void pharaon(int *array, int n, int biggest)
{
    int largest = biggest;
    int left = 2 * biggest + 1;
    int right = 2 * biggest + 2;
    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != biggest)
    {
        swap(array[largest], array[biggest]);
        pharaon(array, n, largest);
    }

}
void pharaoning (int *array, int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
    {
        pharaon(array,n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(array[0],array[i]);
        pharaon(array, i, 0);
    }
}


int main()
{
    int n = 0;
    cout <<"Enter number of elements: ";
    cin >> n;
    int *arr = nullptr;
    arr = new int[n];
    cout <<"Enter elements of your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pharaoning(arr, n);
    cout <<"Sorted array: ";
    print_array(arr, n);
    delete[] arr;
    return 0;
}


