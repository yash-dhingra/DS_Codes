#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
class stack
{

    struct node *top;

public:
    void insert(int new_data)
    {
        struct node *new_node = new node;
        new_node->data = new_data;
        new_node->next = top;
        top = new_node;
    }
    void display()
    {
        struct node *ptr;
        ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    stack()
    {
        top = NULL;
    }
};
int main()
{
    stack list;
    for (int i = 0; i < 10; i++)
    {
        list.insert(rand() % 10);
    }

    list.display();
}
