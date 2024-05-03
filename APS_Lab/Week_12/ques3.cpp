// C++ program to illustrate the size() function
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct ele
{
    int num;
    char dir;
};

int main()
{
    string str1 = "vish";
    string str2 = "vishal";

    int str1_len = str1.length();
    int str2_len = str2.length();

    ele temp;
    temp.num = 0;
    temp.dir = 'n';

    vector<vector<ele>> grid(str1_len + 1, vector<ele>(str2_len + 1, temp));

    for (int i = 1; i <= str1_len; i++)
    {
        for (int j = 1; j <= str2_len; j++)
        {
            if (str1[i - 1] != str2[j - 1])
            {
                grid[i][j].num = max(grid[i - 1][j].num, grid[i][j - 1].num);
                if (max(grid[i - 1][j].num, grid[i][j - 1].num) == grid[i - 1][j].num)
                    grid[i][j].dir = 'u';
                else
                    grid[i][j].dir = 'l';
            }
            else
            {
                grid[i][j].num = grid[i - 1][j - 1].num + 1;
                grid[i][j].dir = 'd';
            }
        }
    }

    // Printing the array

    cout << "Minimum Number of Edit Operation: "<<str1_len+str2_len-2*grid[str1_len][str2_len].num;

    return 1;
}
