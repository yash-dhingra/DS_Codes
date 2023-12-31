#include <iostream>
#include <cstdlib>
using namespace std;

void insert(int hashtable[], int data, int len)
{
    if (hashtable[data % 10] != -1)
    {
        for (int i = data % 10; i < len; i++)
        {
            if (hashtable[i] == -1)
            {
                hashtable[i] = data;
                return;
            }
        }
        for (int i = 0; i < data % 10; i++)
        {
            if (hashtable[i] == -1)
            {
                hashtable[i] = data;
                return;
            }
        }
    }
    else
    {
        hashtable[data % 10] = data;
    }
}

int search(int hashtable[], int data, int len)
{
    if (hashtable[data % 10] == data)
        return 1;
    int flag = 0;
    for (int i = data % 10; i < len; i++)
    {
        if (hashtable[i] == data)
        {
            return 1;
        }
    }
    for (int i = 0; i < data % 10; i++)
    {
        if (hashtable[i] == data)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int array[5];
    int hashtable[10];
    for (int i = 0; i < 10; i++)
        hashtable[i] = -1;
    int len = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < len - 1; i++)
    {
        array[i] = rand() % 100;
        insert(hashtable, array[i], len);
    }
    array[len - 1] = 47;
    insert(hashtable, array[len - 1], len);
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "i: " << i << ": " << hashtable[i] << endl;
    }

    cout << endl
         << "Is 7 Present?: " << search(hashtable, 46, len) << endl;
}
