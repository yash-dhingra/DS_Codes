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

    void reverse()
    {
        Node *prev, *current, *next;
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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

    void middle()
    {
        Node *ptr = head;
        Node *middle = head;
        while (ptr != NULL && ptr->next != NULL)
        {
            middle = middle->next;
            ptr = ptr->next->next;
        }
        cout << "Middle Element: " << middle->data << endl;
    }
};

int main()
{
    stack stack;
    stack.insert(5);
    stack.insert(6);
    stack.insert(7);
    stack.insert(10);

    stack.display();

    cout << endl;

    stack.middle();
}
