#include <iostream>
#include <cstdlib>
using namespace std;

void insert(int hashtable[], int data, int len)
{
    if (hashtable[data % 10] != -1)
    {
        int i = 0;
        int h1 = data % 10;
        int h2 = 7 - data % 7;
        int ht = h1;
        while (hashtable[ht] != -1)
        {
            ht = (h1 + h2 * i) % 10;
            i++;
        }
        hashtable[ht] = data;
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
    int i = 1;
    int h1 = data % 10;
    int h2 = 7 - data % 7;
    int ht = (h1 + h2 * i) % 10;
    while (hashtable[ht] != data && ht != data % 10)
    {
        ht = (h1 + h2 * i) % 10;
        i++;
        cout << "ht: " << ht << endl;
        //        if(hashtable[ht]==data) return 1;
    }
    if (hashtable[ht] == data)
        return 1;

    return 0;
}

int main()
{
    int array[5];
    int hashtable[10];
    for (int i = 0; i < 10; i++)
        hashtable[i] = -1;
    int len = sizeof(array) / sizeof(array[0]);

    array[0] = 5;
    insert(hashtable, array[0], len);

    array[1] = 25;
    insert(hashtable, array[1], len);

    array[2] = 15;
    insert(hashtable, array[2], len);

    array[3] = 35;
    insert(hashtable, array[3], len);

    array[4] = 95;
    insert(hashtable, array[4], len);

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
         << "Is 7 Present?: " << search(hashtable, 5, len) << endl;
}
