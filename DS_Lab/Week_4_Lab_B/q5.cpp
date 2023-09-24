#include <iostream>

using namespace std;

void hailstone(int num)
{
    cout << num << " ";
    if (num == 1)
    {
        return;
    }

    else if (num % 2 == 0)
    {
        hailstone(num / 2);
    }
    else
    {
        hailstone((num * 3) + 1);
    }
}

int main()
{
    int num = 13;
    hailstone(13);
    return 0;
}
