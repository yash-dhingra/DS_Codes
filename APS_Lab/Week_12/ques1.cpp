#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <climits>
using namespace std;

int if_vowel(char c)
{
    int cnt = 0;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        cnt = 1;
    }
    return cnt;
}

int main()
{
    string str = "artyebui";
    int k = 2;
    int str_len = str.length();

    vector<vector<int>> grid(str_len + 1, vector<int>(str_len + 1, 0));

    for (int i = 1; i <= str_len; i++)
    {
        grid[i][i] = if_vowel(str[i - 1]);
    }

    for (int d = 1; d <= str_len - 1; d++)
    {
        for (int i = 1; i < str_len-d; i++)
        {
            int j = i + d;
            grid[i][j] = grid[i][j - 1] + if_vowel(str[j - 1]);
        }
    }

    // Print substrings where grid value is equal to 2
    for (int i = 1; i <= str_len; i++)
    {
        for (int j = i; j <= str_len; j++)
        {
            if (grid[i][j] == k)
            {
                cout << str.substr(i - 1, j - i + 1) << endl;
            }
        }
    }
}
