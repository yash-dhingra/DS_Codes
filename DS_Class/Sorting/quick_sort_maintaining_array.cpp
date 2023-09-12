#include <iostream>
#include <stdlib.h>
using namespace std;

void display(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
}

int partition_sort(int *arr, int l, int r)
{
    cout << "before operation: ";
    display(arr, 5);
    cout << "    l_Index: " << l;
    cout << "    r_Index: " << r;
    cout << endl;
    int pivot = r;
    int ll = 0, lr = 0, lp = 0;
    int larr[r - l + 1], parr[r - l + 1], rarr[r - l + 1];
    //    cout <<"Length: "<< r-l<<"\n";
    for (int i = l; i <= r; i++)
    {

        if (arr[i] < arr[pivot])
        {
            larr[ll] = arr[i];
            ll++;
            //            cout << "Current ele: "<<ll<<"\n";
        }
        else if (arr[i] == arr[pivot])
        {
            parr[lp] = arr[i];
            lp++;
        }
        else
        {
            rarr[lr] = arr[i];
            lr++;
        }
    }
    int k = l;
    int ret_pivot;
    for (int i = 0; i < ll; i++)
    {
        arr[k] = larr[i];
        k++;
    }
    ret_pivot = k;
    for (int i = 0; i < lp; i++)
    {
        arr[k] = parr[i];
        k++;
    }

    for (int i = 0; i <= lr; i++)
    {
        arr[k] = rarr[i];
        k++;
    }
    cout << "after operation: ";
    display(arr, 5);
    cout << "    Pivot_Index: " << ret_pivot;
    cout << endl;

    return ret_pivot;
}

void quick_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pivot = partition_sort(arr, l, r);
        quick_sort(arr, l, pivot - 1);
        quick_sort(arr, pivot + 1, r);
    }
}

int main()
{
    int array[] = {1, 4, 5, 4, 2};
    quick_sort(array, 0, 4);
    //    cout << "Pivot Output: "<<partition_sort(array, 0, 4)<<endl;

    int len = 5;
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
}
