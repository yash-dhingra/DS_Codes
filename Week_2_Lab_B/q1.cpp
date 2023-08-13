#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
class linked_list
{

    struct node *head;

public:
    void insert(int new_data)
    {
        struct node *new_node = new node;
        new_node->data = new_data;
        new_node->next = head;
        head = new_node;
    }
    void display()
    {
        struct node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    linked_list()
    {
        head = NULL;
    }
};
int main()
{
    linked_list list;
    for (int i = 0; i < 10; i++)
    {
        list.insert(rand() % 10);
    }

    list.display();
}
