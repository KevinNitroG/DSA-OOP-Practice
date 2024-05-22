#include <iostream>
using namespace std;

void PrintArray(const int a[], const int &n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// i la index
void Heapify(int arr[], const int &n, const int &i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l <= n && arr[l] > arr[max])
        max = l;
    if (r <= n && arr[r] > arr[max])
        max = r;
    if (max != i)
    {
        swap(arr[max], arr[i]);
        Heapify(arr, n, max);
    }
}

void HeapSort(int arr[], const int &n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        Heapify(arr, i - 1, 0);
    }
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, size);
    PrintArray(arr, size);
    return 0;
}
