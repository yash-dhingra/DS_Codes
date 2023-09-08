#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Kindly Enter the length of The array: ";
    int len;
    cin >> len;
    int *A = new int[len];
    for (int i = 0; i < len; i++)
        A[i] = rand() % 100;

    for (int i = 0; i < len; i++)
        if (A[i] % 2 == 0)
            cout << A[i] << " ";
    for (int i = 0; i < len; i++)
        if (A[i] % 2 != 0)
            cout << A[i] << " ";
}
