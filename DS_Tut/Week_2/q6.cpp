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

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    void n_term_behind(int n)
    {
        Node *iter = head, *term = head;
        for (int i = 0; i < n; i++)
        {
            iter = iter->next;
        }
        while (iter != NULL)
        {
            iter = iter->next;
            term = term->next;
        }
        cout << "\nNth Element from the rear is: " << term->data << endl;
    }

    void del_last(int x)
    {
        Node *iter = head, *occ_prev = NULL, *occ_pres = NULL;
        while (iter != NULL)
        {

            if (iter->data == x)
            {
                //                occ_prev=occ_pres;
                occ_pres = iter;
            }
            iter = iter->next;
        }

        iter = head;

        while (iter->next != occ_pres)
        {
            iter = iter->next;
        }
        //        cout << "Iter: "<<occ_pres->next->data;
        iter->next = iter->next->next;
    }
};

int main()
{
    stack stack;
    for (int i = 0; i < 11; i++)
    {
        stack.insert(rand() % 10);
    }
    stack.insert(9);
    stack.display();
    stack.del_last(0);
    cout << endl;
    stack.display();
}
