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

    int coin[] = {2, 3, 5, 10};
    int siz = sizeof(coin) / sizeof(coin[0]);
    int weight_needed = 7;

    set<int> coins(coin, coin + siz);

    set<int>::iterator iter = coins.begin();

    vector<vector<int>> grid(siz, vector<int>(weight_needed + 1, 0));

    // Initialize Grid

    for (int i = 0; i < siz; i++)
    {
        grid[i][0] = 1;
    }

    // Initialize the first row

    for (int j = 1; j <= weight_needed; j++)
    {
        int current_coin = *(coins.begin());
        if (j % current_coin == 0)
        {
            grid[0][j] = 1;
        }
    }

    iter++;

    for (int i = 1; i < siz; i++)
    {
        int current_coin = *(iter);
        for (int j = 1; j <= weight_needed; j++)
        {
            if (j >= current_coin)
                grid[i][j] = grid[i - 1][j] + grid[i][j - current_coin];
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

    return 1;
}
