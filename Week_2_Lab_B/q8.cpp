#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
class linkedlist
{

    struct node *head;

public:
    void push(int data)
    {
        node *new_ptr = new node;
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            new_ptr->data = data;
            new_ptr->next = head;
            head->prev = new_ptr;
            new_ptr->prev = NULL;
            head = new_ptr;
        }
    }

    void insert(int data, int pos)
    {
        int cntr = 0;
        node *ptr = new node;
        ptr = head;
        while (ptr != NULL)
        {
            if (pos == cntr)
            {
                node *new_node = new node;
                new_node->data = data;
                new_node->prev = ptr->prev;
                new_node->next = ptr;
                ptr->prev->next = new_node;
            }
            ptr = ptr->next;
            cntr++;
        }
    }

    void display()
    {
        node *ptr = new node;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    linkedlist()
    {
        head = NULL;
    }
};
int main()
{
    linkedlist list;

    list.push(5);
    list.push(8);
    list.push(6);
    list.push(9);

    list.display();

    cout << endl;

    list.insert(0, 1);
    cout << "\n";

    list.display();

    cout << endl;
}
