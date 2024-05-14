#include <iostream>
using namespace std;

void PrintArray(const int a[], const int &n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Merge(int a[], const int &l, const int &m, const int &r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int a1[n1], a2[n2];
    int i, j;
    for (i = 0; i < n1; ++i)
        a1[i] = a[i + l];
    for (i = 0; i < n2; ++i)
        a2[i] = a[i + m + 1];
    i = j = 0;
    int index = l;
    while (i < n1 && j < n2)
        if (a1[i] < a2[j])
            a[index++] = a1[i++];
        else
            a[index++] = a2[j++];
    while (i < n1)
        a[index++] = a1[i++];
    while (j < n2)
        a[index++] = a2[j++];
}

void MergeSort(int a[], const int &l, const int &r)
{
    if (l >= r)
        return;
    int m = (r + l) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, size - 1);
    PrintArray(arr, size);
    return 0;
}
