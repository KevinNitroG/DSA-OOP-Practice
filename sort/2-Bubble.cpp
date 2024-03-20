#include <iostream>

using namespace std;

void PrintArray(const int a[], const int &n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void InsertionSort(int a[], const int &n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, size);
    PrintArray(arr, size);
    return 0;
}
