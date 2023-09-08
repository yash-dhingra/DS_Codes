#include <iostream>
#include <stdlib.h>
using namespace std;

void bubble_sort(int *array, int len)
{
    int temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            if (array[j - 1] > array[j])
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int *arr = new int[50];
    for (int i = 0; i < 50; i++)
    {
        arr[i] = rand() % 10;
    }

    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    int len = 50;

    bubble_sort(arr, len);

    cout << "\nAfter Sorting\n";

    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
}