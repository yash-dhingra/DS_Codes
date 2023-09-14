#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    Node *head, *ptr;

public:
    Linked_List()
    {
        head = NULL;
    }

    void push(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        if (head == NULL)
        {
            head = new_node;
            new_node->next = new_node;
            ptr = head;
        }
        else
        {
            ptr->next = new_node;
            new_node->next = head;
            ptr = new_node;
        }
    }

    void display()
    {
        Node *iter = head;
        do
        {
            cout << iter->data << " ";
            iter = iter->next;
        } while (iter != head);
    }

    void last_sele()
    {
        // ****Note we have taken head pointer as rear pointer in this example hence the code is conceptually correct!!
        Node *iter = head;
        while (iter->next != head)
        {
            iter = iter->next;
        }
        cout << iter->data << " ";
    }
};

int main()
{

    Linked_List list;
    list.push(5);
    list.push(10);
    list.push(11);

    list.display();

    cout << endl;

    list.last_sele();
}
