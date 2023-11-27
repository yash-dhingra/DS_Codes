#include <iostream>
using namespace std;

int sum = 0;

int minofarray(int array[], int l, int r)
{
    if (l == r)
    {
        return array[l];
    }

    else
    {

        int mid = (r + l) / 2;

        int leftsum = minofarray(array, l, mid);
        int rightsum = minofarray(array, mid + 1, r);
        if (leftsum < rightsum)
            return leftsum;
        return rightsum;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(array) / sizeof(array[0]);
    //    sumofarray(array,0,len-1);
    cout << "Minimum is: " << minofarray(array, 0, len - 1) << endl;
}
