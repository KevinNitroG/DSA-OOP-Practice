#include <iostream>

using namespace std;

void PrintArray(const int a[], const int &n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int Partition(int a[], const int &l, const int &r)
{
    int pi = a[r];
    int i = l - 1;
    for (int j = l; j <= r; ++j)
        if (a[j] <= pi)
            swap(a[++i], a[j]);
    swap(a[++i], a[r]);
    return i;
}

void QuickSort(int a[], const int &l, const int &r)
{
    if (l >= r)
        return;
    int pi = Partition(a, l, r);
    QuickSort(a, l, pi - 1);
    QuickSort(a, pi + 1, r);
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, size - 1);
    PrintArray(arr, size);
    return 0;
}
