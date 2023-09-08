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

    int count()
    {
        struct node *ptr;
        ptr = head;
        int coun = 0;
        while (ptr != NULL)
        {
            coun += 1;
            ptr = ptr->next;
        }
        return coun;
    }

    int max()
    {
        struct node *ptr;
        ptr = head;
        int ma = ptr->data;
        while (ptr != NULL)
        {
            if (ma < ptr->data)
                ma = ptr->data;
            ptr = ptr->next;
        }
        return ma;
    }

    int min()
    {
        struct node *ptr;
        ptr = head;
        int ma = ptr->data;
        while (ptr != NULL)
        {
            if (ma > ptr->data)
                ma = ptr->data;
            ptr = ptr->next;
        }
        return ma;
    }

    void insert_pos(int data, int pos)
    {
        if (pos < this->count())
        {
            int current_pos = 0;
            struct node *ptr;
            ptr = head;
            while (ptr != NULL)
            {
                if (pos == current_pos)
                {
                    struct node *newnode = new node;
                    newnode->data = data;
                    newnode->next = ptr->next;
                    ptr->next = newnode;
                    break;
                }
                current_pos += 1;
            }
        }
        else
            cout << "Invalid pos entered";
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

    cout << endl;

    cout << "after inserting on second position" << endl;

    list.insert_pos(99, 2);

    list.display();
    cout << endl;
}
