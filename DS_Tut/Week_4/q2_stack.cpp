#include <iostream>
#include <stack>
using namespace std;

void natural_number(int n)
{
    stack<int> stack;
    while (true)
    {
        //        cout <<"run";
        if (n == 1)
        {

            stack.push(1);
            while (!stack.empty())
            {
                cout << stack.top() << " ";
                stack.pop();
            }
            break;
        }
        //        cout <<n<<" ";
        stack.push(n);
        n--;
    }
}

int main()
{
    natural_number(50);
}
