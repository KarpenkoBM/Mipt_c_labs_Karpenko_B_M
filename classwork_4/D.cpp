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

void quick_sort(int *array, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int pivot = array[(i + j) / 2];

        while (true)
        {
            while (array[i] < pivot)
            {
                i++;
            }
            while (array[j] > pivot)
            {
                j--;
            }
            if (i >= j)
            {
                pivot = j;
                break;
            }
            swap(array[i],array[j]);
            i++;
            j++;
        }
        quick_sort(array, left, pivot);
        quick_sort(array, pivot + 1, right);
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
    quick_sort(arr, 0 , n - 1);
    cout <<"Sorted array: ";
    print_array(arr, n);
    delete[] arr;
    return 0;
}
