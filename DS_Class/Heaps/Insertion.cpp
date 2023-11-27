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

int main()
{
    //    Heap heap(100);
    //    heap.insert(20);
    int array[100] = {40, 35, 15, 30, 10, 12, 6, 5, 20};
    int len = 9;
    insert(array, len, 50);
    //    heap.insert(50);
    len++;
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    //    heap.display();
}
