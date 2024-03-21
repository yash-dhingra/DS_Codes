#include <iostream>
#include <vector>
#include <limits.h>
#define V 5

using namespace std;

int min_ele(vector<int> &arr)
{
    int temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[temp] > arr[i])
        {
            temp = i;
        }
    }
    int temp_ele = arr[temp];
    arr[temp] = INT_MAX;
    return temp_ele;
}

int main()
{

    vector<int> arr;
    for (int i = 0; i < 7; i++)
    {
        arr.push_back(rand() % 100);
    }

    int temp_min1 = min_ele(arr);
    int temp_min2 = min_ele(arr);

    cout << "Minimum Product of Numbers are: " << temp_min1 << " X " << temp_min2 << " = " << temp_min1 * temp_min2 << endl;
}
