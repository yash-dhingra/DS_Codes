#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class stack
{
    Node *head, *tail;

public:
    stack()
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

    void reverse_display(Node *ptr)
    {
        if (ptr != NULL)
        {
            reverse_display(ptr->next);
            cout << ptr->data << " ";
        }
    }

    Node *ret_head()
    {
        return head;
    }
};

int main()
{
    stack stack;
    stack.insert(5);
    stack.insert(6);
    stack.insert(7);

    stack.reverse_display(stack.ret_head());
}