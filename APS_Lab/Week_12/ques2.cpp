#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {5, 15, -30, 10, -5, 40, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> grid(len + 1, vector<int>(len + 1, 0));

    //    Innitalize the diagnals

    for (int i = 1; i <= len; i++)
    {
        grid[i][i] = arr[i - 1];
    }

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    for (int d = 1; d <= len - 1; d++)
    {
        for (int i = 1; i < len - d; i++)
        {
            int j = i + d;
            grid[i][j] = grid[i][j - 1] + arr[j - 1];
        }
    }

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
