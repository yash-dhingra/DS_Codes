#include <iostream>
using namespace std;
struct node1
{
    int info;
    node1 *rp;
};
struct node2
{
    int listno;
    node1 *rp;
    node2 *dp;
};
int main()
{
    node2 *start = NULL, *temp, *head;
    node1 *t, *h;
    int x = 1, i = 1, y = 1, m = 0, k;
    while (x)
    {
        temp = new node2;
        temp->rp = NULL;
        temp->dp = NULL;
        temp->listno = i++;
        if (start == NULL)
        {
            start = head = temp;
        }
        else
        {
            head->dp = temp;
            head = temp;
        }
        y = 1;
        while (y)
        {
            t = new node1;
            t->rp = NULL;
            t->info = rand() % 100;
            if (temp->rp == NULL)
                temp->rp = h = t;
            else
            {
                h->rp = t;
                h = t;
            }
            y = rand() % 10;
        }
        x = rand() % 10;
    }
    temp = start;
    while (temp != NULL)
    {
        int c = 0;
        t = temp->rp;
        cout << temp->listno << ": ";
        while (t != NULL)
        {
            cout << t->info << " ";
            t = t->rp;
            c++;
        }
        if (m < c)
        {
            m = c;
            k = temp->listno;
        }
        cout << "\n";
        temp = temp->dp;
    }

    cout << "\n\n"
         << m << "   " << k;

    return 0;
}
