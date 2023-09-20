#include <iostream>
using namespace std;

int count_digits(int num)
{
    int cnt = 0;
    while (num % 10 != 0)
    {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int digit_ret(int num, int digit)
{
    int divi = 1;
    for (int i = 0; i < digit; i++)
    {
        divi *= 10;
    }
    return ((num % divi - num % (divi / 10)) / (divi / 10));
}

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

    void push(int data)
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

    void radix_sort()
    {
        int max_digits = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (count_digits(ptr->data) > max_digits)
                (
                    max_digits = count_digits(ptr->data));
            ptr = ptr->next;
        }
        // Innitialize the Node array;
        stack *ptr_array[max_digits][10];

        for (int i = 0; i <= max_digits; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                ptr_array[i][j] = new stack;
            }
        }

        // The sorting Begins
        ptr = head;
        while (ptr != NULL)
        {
            ptr_array[0][digit_ret(ptr->data, 1)]->push(ptr->data);
            cout << "Data: " << ptr->data << endl;
            cout << "Digits: " << digit_ret(ptr->data, 1) << endl;

            ptr = ptr->next;
        }
        ptr_array[0][6]->display();

        for (int i = 1; i <= max_digits; i++)
        {
            continue;
        }
    }
};

int main()
{
    stack stack;
    stack.push(100);
    stack.push(60);
    stack.push(73);
    stack.radix_sort();
    stack.display();
}