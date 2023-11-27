#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class queue
{
    Node *head, *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int data)
    {
        Node *new_ptr = new Node;
        new_ptr->data = data;
        new_ptr->next = NULL;
        if (tail == NULL)
        {
            tail = new_ptr;
            head = tail;
        }

        else
        {
            tail->next = new_ptr;
            tail = new_ptr;
        }
    }

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    int isempty()
    {
        if (head == NULL)
        {
            return 1;
        }
        return 0;
    }
    int pop()
    {
        int data = head->data;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        return data;
    }
};

void bfs(int graph[][7], int start, int num)
{
    queue qu;
    int visited[7] = {0};
    cout << start << "-";
    qu.insert(start);
    visited[start] = 1;
    while (qu.isempty() != 1)
    {
        start = qu.pop();
        //        cout << start<<"-";
        for (int i = 1; i < num; i++)
        {

            if (graph[start][i] == 1 && visited[i] == 0)
            {
                cout << i << "-";
                visited[i] = 1;
                qu.insert(i);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    bfs(G, 1, 7);
}
