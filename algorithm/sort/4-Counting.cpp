#include <iostream>

using namespace std;

void PrintArray(const int a[], const int &n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int FindMax(int a[], const int &n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
        if (a[max] < a[i])
            max = i;
    return a[max];
}

int *CountingSort(int inputArray[], const int &n)
{
    int M = FindMax(inputArray, n);
    int *processArray = new int[M]{0};
    for (int i = 0; i < n; i++)
        processArray[inputArray[i]]++;
    for (int i = 1; i < M; i++)
        processArray[i] += processArray[i - 1];
    int *outputArray = new int[n];
    for (int i = 0; i < n; i++)
        outputArray[processArray[--inputArray[i]]] = inputArray[i];
    delete[] processArray;
    return outputArray;
}

int main()
{
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *sortedArray = CountingSort(arr, size);
    PrintArray(sortedArray, size);
    return 0;
}
