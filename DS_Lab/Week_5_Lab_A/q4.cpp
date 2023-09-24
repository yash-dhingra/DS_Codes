#include <iostream>
using namespace std;

int kthh(int arr[], int len, int kth)
{
    for (int i = 0; i < kth; i++)
    {
        cout << "run" << endl
             << kth;
        for (int j = 1; j < len - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return arr[len - kth];
}

int kthl(int arr[], int len, int kth)
{

    for (int i = 0; i < len; i++)
    {
        cout << "run" << kth << endl;
        for (int j = 1; j < len - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return arr[kth - 1];
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << kthl(arr, len, 4) << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}
