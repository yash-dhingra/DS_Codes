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
    Linked_List stack = prime_factors(26);

    stack.display();
}