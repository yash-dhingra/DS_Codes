#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b < c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

int sum = 0;

int sumofarray(int array[], int l, int r)
{
    if (r - l == 1)
    {
        return array[r] - array[l];
    }
    else if (r == l)
    {
        return 99999;
    }

    else
    {

        int mid = (r + l) / 2;
        int left = sumofarray(array, l, mid);
        int midd = sumofarray(array, mid, mid + 1);
        int right = sumofarray(array, mid + 1, r);

        return min(left, midd, right);
    }
}

int main()
{
    int array[] = {-10, 2, 5, 10, 15, 20, 56};
    int len = sizeof(array) / sizeof(array[0]);
    //    sumofarray(array,0,len-1);
    cout << "Sum is: " << sumofarray(array, 0, len - 1) << endl;
}
