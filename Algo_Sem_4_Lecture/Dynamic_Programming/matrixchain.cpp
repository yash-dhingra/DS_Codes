// C++ program to illustrate the size() function
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
    int arr[] = {5, 4, 6, 2, 7};
    int siz = sizeof(arr) / sizeof(arr[0]);
    // Innit Grid Array
    vector<vector<int>> m(siz, vector<int>(siz, 0));

    vector<vector<int>> s(siz, vector<int>(siz, 0));

    for (int d = 1; d <= siz - 1; d++)
    {
        for (int i = 1; i < siz - d; i++)
        {
            int j = i + d;
            int minn = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < minn)
                {
                    minn = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = minn;
        }
    }

    cout << m[1][siz - 1];

    return 1;
}
