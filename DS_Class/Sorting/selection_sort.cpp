#include <iostream>
#include <stdlib.h>
using namespace std;

void display(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
}

void selection_sort(int *array, int len)
{
    int min, min_index, temp;

    for (int i = 0; i < len; i++)
    {
        min = array[i];
        min_index = i;
        for (int j = i; j < len; j++)
        {
            if (min > array[j])
            {
                min = array[j];
                min_index = j;
            }
        }
        if (min_index != i)
        {
            array[min_index] = array[i];
            array[i] = min;
        }
        // display(array, len);
        // cout << "\n";
    }
}

void innit(int *array, int len)
{

    for (int i = 0; i < 50; i++)
    {
        array[i] = rand() % 10;
    }
}

int main()
{
    int len = 10;
    int *arr = new int[len];

    innit(arr, len);
    display(arr, len);
    cout << "\nafter Sorting\n";
    selection_sort(arr, len);
    display(arr, len);
}