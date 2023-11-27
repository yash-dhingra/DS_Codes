#include <iostream>
using namespace std;

int sum = 0;

int sumofarray(int array[], int l, int r)
{
    if (l == r)
    {
        return array[l];
    }

    else
    {

        int mid = (r + l) / 2;

        int leftsum = sumofarray(array, l, mid);
        int rightsum = sumofarray(array, mid + 1, r);
        return leftsum + rightsum;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(array) / sizeof(array[0]);
    //    sumofarray(array,0,len-1);
    cout << "Sum is: " << sumofarray(array, 0, len - 1) << endl;
}
