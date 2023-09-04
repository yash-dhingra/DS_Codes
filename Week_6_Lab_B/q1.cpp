#include <iostream>
using namespace std;

bool in(int *array, int len, int ele)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] == ele)
        {
            return 1;
        }
    }
    return 0;
}

void func(int *array, int len)
{
    int freq[len];
    int count;
    for (int i = 0; i < len; i++)
    {
        count = 0;
        for (int j = 0; j < len; j++)
        {
            if (array[i] == array[j])
                count++;
        }
        freq[i] = count;
    }

    int temp_array[len];
    for (int i = 1; i <= len; i++)
    {
        temp_array[i - 1] = i;
    }

    for (int i = 0; i < len; i++)
    {
        if (!in(array, len, temp_array[i]))
        {
            cout << "Missing: " << temp_array[i] << endl;
            break;
        }
    }
    cout << "Muliple Elements: ";

    for (int i = 0; i < len; i++)
    {
        if (freq[i] == 2)
        {
            cout << array[i];
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 3};

    func(arr, 3);
}