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

    int coin[] = {1, 5, 6, 9};
    int siz = sizeof(coin) / sizeof(coin[0]);
    int weight_needed = 10;

    set<int> coins(coin, coin + siz);

    set<int>::iterator iter = coins.begin();

    vector<vector<int>> grid;

    // Initialize Grid

    for (int i = 0; i < siz; i++)
    {
        vector<int> temp(weight_needed + 1, 0);
        grid.push_back(temp);
    }

    // Initialize the first row

    for (int j = 1; j <= weight_needed; j++)
    {
        int current_coin = *(coins.begin());
        if (j % current_coin == 0)
        {
            grid[0][j] = j / current_coin;
        }
    }

    iter++;

    for (int i = 1; i < siz; i++)
    {
        int current_coin = *(iter);
        for (int j = 1; j <= weight_needed; j++)
        {
            if (j >= current_coin)
                grid[i][j] = min(grid[i - 1][j], 1 + grid[i][j - current_coin]);
            else
                grid[i][j] = grid[i - 1][j];
        }
        iter++;
    }

    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j <= weight_needed; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // Printing out the denomination used
    iter = coins.end();
    iter--;
    int temp_coin = siz - 1;
    int temp_weight = weight_needed;
    while (temp_coin >= 0 && temp_weight != 0)
    {
        if (grid[temp_coin][temp_weight] != grid[temp_coin - 1][temp_weight])
        {
            cout << *(iter) << " ";
            temp_weight -= *(iter);
        }
        else
        {
            temp_coin--;
            iter--;
        }
    }

    return 1;
}
