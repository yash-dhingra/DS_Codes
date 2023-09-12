#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    // Put Values in the arrays

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[i + mid + 1];
    }

    // Comparision and Merging Respectively
    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        //        else if (a[i] == b[j])
        //        {
        //            arr[k] = a[i];
        //            k++;
        //            arr[k] = a[i];
        //            k++;
        //            i++;
        //            j++;
        //        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    // Empty Whats Left
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    int array[] = {3, 4, 5, 4, 2};

    //     innit(array, 10);
    display(array, 5);
    sort(array, 0, 4);
    cout << "\nafter sorting!!\n";
    display(array, 5);
}
