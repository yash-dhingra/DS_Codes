#include <iostream>
using namespace std;

int sum = 0;

int factorial(int l, int r)
{
    if (l == r)
    {
        return l;
    }

    else
    {
        int mid = (r + l) / 2;

        int left = factorial(l, mid);
        int right = factorial(mid + 1, r);
        return left * right;
    }
}

int main()
{

    cout << "Factorial is: " << factorial(1, 5) << endl;
}
