#include <iostream>
#include <cstdlib>
using namespace std;

void insert(int hashtable[], int data, int len)
{
    if (hashtable[data % 10] != -1)
    {
        for (int i = data % 10; i < len; i++)
        {
            int temp_i = i;
            i = i * i;
            //            cout << "run"<<endl;
            if (hashtable[i] == -1)
            {
                hashtable[i] = data;
                return;
            }
            i = temp_i;
        }
        for (int i = 0; i < data % 10; i++)
        {
            int temp_i = i;
            i = i * i;
            //            cout << "run"<<endl;
            if (hashtable[i] == -1)
            {
                hashtable[i] = data;
                return;
            }
            i = temp_i;
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
    for (int i = data % 10; i < len; i++)
    {
        int temp_i = i;
        i = i * i;
        if (hashtable[i] == data)
        {
            return 1;
        }
        i = temp_i;
    }
    for (int i = 0; i < data % 10; i++)
    {
        int temp_i = i;
        i = i * i;
        if (hashtable[i] == data)
        {
            return 1;
        }
        i = temp_i;
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
    array[0] = 10;
    insert(hashtable, array[0], len);

    array[1] = 11;
    insert(hashtable, array[1], len);

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
         << "Is 7 Present?: " << search(hashtable, 47, len) << endl;
}
