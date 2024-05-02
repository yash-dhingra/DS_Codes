// C++ program to illustrate the size() function
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{

    int arr[] = {2, 3, 5, 7, 10};
    int siz = sizeof(arr) / sizeof(arr[0]);
    int sum_needed = 14;

    set<int> arra(arr, arr + siz);

    set<int>::iterator iter = arra.begin();

    vector<vector<int>> grid(siz, vector<int>(sum_needed + 1, 0));

    // Initialize Grid

    for (int i = 0; i < siz; i++)
    {
        grid[i][0] = 1;
    }

    // Initialize the first row

    grid[0][*iter] = 1;

    iter++;
    int temp_sum;

    for (int i = 1; i < siz; i++)
    {
        int current_num = *(iter);
        for (int j = 1; j <= sum_needed; j++)
        {
            if (j >= current_num)
            {
                if (grid[i - 1][j] == 1)
                    grid[i][j] = 1;
                else
                    grid[i][j] = grid[i - 1][j - current_num];
            }
            else
            {
                grid[i][j] = grid[i - 1][j];
            }
        }
        iter++;
    }

    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j <= sum_needed; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 1;
}
