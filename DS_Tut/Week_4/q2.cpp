#include <iostream>
using namespace std;

void natural_number(int n)
{
    if (n == 1)
    {
        cout << " " << 1 << " ";
        return;
    }
    natural_number(n - 1);
    cout << " " << n << " ";
}

int main()
{
    natural_number(50);
}
