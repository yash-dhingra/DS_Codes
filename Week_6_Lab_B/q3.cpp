#include <iostream>
using namespace std;

void pairo(int *array, int diff, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (array[i] - array[j] == diff || array[i] - array[j] == -diff)
            {
                cout << "Pair(" << array[i] << "," << array[j] << ")" << endl;
                return;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 20, 3, 2, 50, 80};
    int diff = 78;
    pairo(arr, diff, sizeof(arr) / sizeof(arr[0]));
}