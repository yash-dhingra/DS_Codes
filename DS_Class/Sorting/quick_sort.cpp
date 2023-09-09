#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int i, j, pi;
    i = l - 1;
    j = l;
    pi = arr[r];

    for (j = l; j < r; j++)
    {
        if (arr[j] < pi)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return i + 1;
}

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quick_sort(arr, l, pi - 1);
        quick_sort(arr, pi + 1, r);
    }
}

void innit(int array[], int len)
{

    for (int i = 0; i < 50; i++)
    {
        array[i] = rand() % 10;
    }
}

void display(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int array[] = {1, 27, 4, 3, 4, 5, 6, 74, 2, 10, 10};

    //     innit(array, 10);
    display(array, 11);
    quick_sort(array, 0, 10);
    cout << "\nafter sorting!!\n";
    display(array, 11);
}
