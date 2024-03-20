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
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > a[i])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, size);
    PrintArray(arr, size);
}
