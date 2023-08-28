#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Linked_List_Stack
{
    Node *head;

public:
    void push(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
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

    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow";
            return;
        }
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }

    int top()
    {
        return head->data;
    }

    Linked_List_Stack()
    {
        head = NULL;
    }
};

class Linked_List_Stack_Que
{
    Node *head, *tail;

public:
    Linked_List_Stack_Que()
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

    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow";
            return;
        }
        Node *ptr = head;
        head = head->next;
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

    int top()
    {
        return head->data;
    }
};

int main()
{
    Linked_List_Stack_Que queue;

    Linked_List_Stack stack;

    int flag;

    cout << "Kindly Enter A Line of String: ";

    string str;

    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        queue.push(str[i]);
        stack.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (queue.top() == stack.top())
        {
            flag = 1;
            queue.pop();
            stack.pop();
            continue;
        }
        flag = 0;
        break;
    }

    if (flag == 1)
        cout << "Yesss Pallindrome!!";
    else
        cout << "Nooo!! Pallindrome";
}
