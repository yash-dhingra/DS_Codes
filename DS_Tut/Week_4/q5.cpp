#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;
queue<int> qu;

void move_n_front(int n)
{
    queue<int> qu2;
    int i = 0;
    int data;
    while (!qu.empty())
    {
        i++;
        if (i == n)
        {
            data = qu.front();
            qu.pop();
            cout << i;
            continue;
        }
        qu2.push(qu.front());
        qu.pop();
    }
    qu.push(data);
    while (!qu2.empty())
    {
        qu.push(qu2.front());
        qu2.pop();
    }
}

void display()
{
    queue<int> temp = qu;
    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
}

int main()
{

    for (int i = 1; i <= 10; i++)
    {
        qu.push(i);
    }
    //    display();
    move_n_front(3);
    cout << "\nAfter moving N\n";
    display();
}
