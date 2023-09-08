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

void insertion_sort(int *array, int len)
{
    int j, key;
    for (int i = 1; i < len; i++)
    {
        j = i - 1;
        key = array[i];
        while (array[j] > key && j >= 0)
        {
            display(array, len);
            cout << "Key=" << key;
            cout << endl;
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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
    insertion_sort(arr, len);
    display(arr, len);
}