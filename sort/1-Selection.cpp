#include <iostream>

using namespace std;

void PrintArray(const int a[], const int &n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void SelectionSort(int a[], const int &n)
{
    int max;
    for (int i = 0; i < n - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < n; j++)
            if (a[max] > a[j])
                max = j;
        swap(a[max], a[i]);
    }
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, size);
    PrintArray(arr, size);
}
