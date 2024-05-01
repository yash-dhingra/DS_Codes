// C++ program to illustrate the size() function
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int weights[] = {3, 4, 6, 5};
    int profits[] = {2, 3, 1, 4};
    int siz = sizeof(weights) / sizeof(weights[0]);
    int weight_needed = 8;
    map<int, int> w_p;

    for (int i = 0; i < siz; i++)
    {
        w_p.insert(pair<int, int>(weights[i], profits[i]));
    }
    map<int, int>::iterator iter;

    vector<vector<int>> grid;

    // Initialize Grid

    for (int i = 0; i <= siz; i++)
    {
        vector<int> temp(weight_needed, 0);
        grid.push_back(temp);
    }

    for (int i = 1; i <= siz; i++)
    {
        int current_weight = iter->first;
        int current_profit = iter->second;
        for (int j = 1; j <= weight_needed; j++)
        {
            if (j >= current_weight)
                grid[i][j] = max(grid[i - 1][j], current_profit + grid[i][j - current_weight]);
            else
                grid[i][j] = grid[i - 1][j];
        }
        iter++;
    }

    return 1;
}
