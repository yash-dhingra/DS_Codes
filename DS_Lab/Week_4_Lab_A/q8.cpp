#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    Node *head, *tail;

public:
    Linked_List()
    {
        head = NULL;
    }

    void push(int data)
    {
        Node *new_ptr = new Node;
        new_ptr->data = data;
        new_ptr->next = NULL;
        if (head == NULL)
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

    void del(int n)
    {
        Node *ptr = head, *ptr_before, *ptr_after;

        for (int i = 0; i < n; i++)
        {
            ptr_before = ptr;
            ptr = ptr->next;
        }
        ptr_after = ptr->next;

        ptr_before->next = ptr_after;

        free(ptr);
    }

    void moveNthFront(int n)
    {
        n--;
        Node *ptr = head;
        for (int i = 0; i < n; i++)
        {
            ptr = ptr->next;
        }
        Node *new_head = new Node;
        new_head->data = ptr->data;
        this->del(n);
        new_head->next = head;
        head = new_head;
    }
};

int main()
{
    Linked_List list;

    list.push(5);
    list.push(11);
    list.push(34);
    list.push(67);
    list.push(43);
    list.push(55);
    list.display();
    cout << endl;

    list.moveNthFront(3);

    list.display();
}
