#include <iostream>
using namespace std;

int linear_search(int *arr, int len, int num)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {2, 3, 4, 2, 2, 4, 4, 5, 3, 2, 2, 46, 7, 5, 5, 6, 6, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Finding the index of 46 in the given array: " << linear_search(arr, len, 46) << " ";
}