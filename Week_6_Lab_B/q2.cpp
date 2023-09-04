#include <iostream>
using namespace std;

void floorceil(int *array, int num, int len)
{

    int floor;
    int ceiling;
    if (num < array[0])
    {
        cout << "Floor: "
             << "Doesn't Exist"
             << "  Ceiling: " << array[0] << " ";
        return;
    }

    if (num > array[len - 1])
    {
        cout << "Floor: "
             << array[len - 1]
             << "  Ceiling: "
             << "Doesn't Exist"
             << " ";
        return;
    }

    for (int i = 0; i < len; i++)
    {

        if (array[i] > num)
        {
            floor = array[i - 1];
            ceiling = array[i];
            break;
        }
    }

    cout << "Floor: " << floor << "  Ceiling: " << ceiling << " ";
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int len = sizeof(arr) / sizeof(arr[0]);
    int num = 20;
    floorceil(arr, num, len);
}