#include <iostream>
using namespace std;
int k;
int path[20][2];

void display(int a[4][4], int x1, int y1, int x2, int y2, int n, int t)
{
    cout << x1 << " " << y1 << "\n";
    if (x1 == x2 && y1 == y2)
    {
        k = 1;
    }
    else
    {
        if ((x1 + 1 < n) && a[x1 + 1][y1] != 0)
        {
            ++t;
            path[t][0] = x1+1;
            path[t][1] = y1
            display(a, x1 + 1, y1, x2, y2, n);
            --t;
        }
        if (k == 1)
            return;
        if ((y1 + 1 < n) && a[x1][y1 + 1] != 0)
        {    display(a, x1, y1 + 1, x2, y2, n);
    }
}
}

int main()
{
    int a[4][4] = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 0, 1, 1}}, i, j;
    k = 0;
    display(a, 0, 0, 3, 3, 4);
    if (k == 1)
        cout << "Path Found";
    else
        cout << "No Path";
    return 0;
}