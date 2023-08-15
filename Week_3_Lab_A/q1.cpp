#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    Node *ptr, *head;

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
            new_node->next = head;
            ptr->next = new_node;
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

    void del()
    {
        Node *iter = head;
        Node *iter_prev, *iter_forw;
        do
        {
            iter_prev = iter;
            iter = iter->next;
            bool flag;
            cout << "Do You wanna delete this element(1 for yes and 0 for no): " << iter->data << "?";
            cin >> flag;
            if (flag == 1)
            {
                iter_forw = iter;
                iter_forw = iter_forw->next;
                iter_prev->next = iter_forw;
                //                delete iter;
                if (iter == head)
                {
                    head = iter_forw;
                    break;
                }
            }
            //            For Iterating

        } while (iter != head);
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
    list.del();

    list.display();
}
