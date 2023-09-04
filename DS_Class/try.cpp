#include <iostream>
using namespace std;
int k;

struct Node
{
    int x;
    int y;
    Node *next;
};

class Linked_List
{
    Node *head;

public:
    void push(int x, int y)
    {
        Node *new_node = new Node;
        cout << "x: " << x << "y: " << y << endl;
        new_node->x = x;
        new_node->y = y;
        new_node->next = head;
        head = new_node;
    }

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->x << " " << ptr->y << " " << endl;
            ptr = ptr->next;
        }
    }

    void pop()
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }

    int top()
    {
        return head->x;
    }

    Linked_List()
    {
        head = NULL;
    }
};
Linked_List stack;

void display(int a[4][4], int x1, int y1, int x2, int y2, int n)
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
            stack.push(x1 + 1, y1);
            display(a, x1 + 1, y1, x2, y2, n);
            // stack.pop();
        }
        if (k == 1)
            return;
        if ((y1 + 1 < n) && a[x1][y1 + 1] != 0)
        {
            stack.push(x1, y1 + 1);
            display(a, x1, y1 + 1, x2, y2, n);
            // stack.pop();
        }
    }
}

int main()
{
    int a[4][4] = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 0, 1, 1}}, i, j;
    k = 0;
    display(a, 0, 0, 3, 3, 4);
    if (k == 1)
        cout << "Path Found";
    else
        cout << "No Path";
    cout << "\nPath" << endl;
    stack.display();
    return 0;
}