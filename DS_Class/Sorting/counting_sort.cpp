#include <iostream>
using namespace std;

int max(int arr[], int len)
{
    int num_max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (num_max < arr[i])
        {
            num_max = arr[i];
        }
    }
    return num_max;
}

void count_sort(int arr[], int len)
{
    int max_num = max(arr, len);
    int count_arr[max_num];
    for (int i = 0; i < max_num; i++)
    {
        count_arr[i] = 0;
    }
    //    Doing Count
    for (int i = 0; i < len; i++)
    {
        count_arr[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max_num; i++)
    {
        for (int j = 0; j < count_arr[i]; j++)
        {
            arr[k] = i;
            k++;
        }
    }

    //    Display
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int array[] = {3, 4, 2, 4, 6};
    int len = sizeof(array) / sizeof(array[0]);

    count_sort(array, len);
}
