#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
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

    Linked_List()
    {
        head = NULL;
    }

    int len()
    {
        int size = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            size++;
        }

        return size;
    }

    Linked_List half()
    {
        Linked_List l1, l2, new_list;
        Node *ptr = head;
        int ctr1 = 0, ctr2 = 0;
        for (int i = 0; i < (this->len()) / 2; i++)
        {
            l1.push(ptr->data);
            ptr = ptr->next;
            ctr1++;
        }
        // l1 contains top half and l2 contains bottom half

        while (ptr != NULL)
        {
            l2.push(ptr->data);
            ptr = ptr->next;
            ctr2++;
        }

        for (int i = 0; i < ctr1; i++)
        {
            new_list.push(l1.top());
            l1.pop();
        }

        for (int i = 0; i < ctr2; i++)
        {
            new_list.push(l2.top());
            l2.pop();
        }

        return new_list;
    }
};

int prime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

Linked_List number_system(int num, int base)
{
    Linked_List list;
    while (num != 0)
    {
        list.push(num % base);
        num /= base;
    }
    return list;
}

Linked_List prime_factors(int number)
{
    Linked_List list;
    for (int i = 2; i <= (number / 2); i++)
    {
        if (number % i == 0)
        {

            if (prime(i))
                list.push(i);
        }
    }

    return list;
}

int main()
{

    number_system(10, 2).display();
}