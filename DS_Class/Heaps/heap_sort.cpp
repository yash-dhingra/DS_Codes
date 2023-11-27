#include <iostream>
using namespace std;

void insert(int array[], int len, int data)
{
    array[len] = data;
    int i, j;
    len++;
    i = len / 2;
    j = len;
    i--;
    j--;
    len--;
    while (i >= 0 && array[i] < array[j])
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j++;
        j = i;
        i = i / 2;
        i--;
        j--;
    }
}

void del(int array[], int len)
{
    len--;
    int temp = array[0];
    array[0] = array[len];
    array[len] = temp;
    len++;

    int i, j, c;
    i = 2;
    j = 3;
    c = 1;
    i--;
    j--;
    c--;
    while ((array[c] < array[i] || array[c] < array[j]) && i < len && j < len)
    {
        if (array[i] > array[j])
        {
            int temp = array[i];
            array[i] = array[c];
            array[c] = temp;
            i++;
            j++;
            c++;
            c = i;
            i = c * 2;
            j = c * 2 + 1;
            i--;
            j--;
            c--;
        }
        if (array[i] < array[j])
        {
            int temp = array[j];
            array[j] = array[c];
            array[c] = temp;
            i++;
            j++;
            c++;
            c = j;
            i = c * 2;
            j = c * 2 + 1;
            i--;
            j--;
            c--;
        }
    }
}

void sort(int array[], int len)
{
    while (len <= 0)
    {
        del(array, len);
        len--;
    }
}

int main()
{

    int array[100] = {40, 35, 30, 15, 10, 25, 5};
    int len = 7;
    sort(array, len);
    //    del(array,len);
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
}
