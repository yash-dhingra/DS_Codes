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

    Linked_List concat(Linked_List list)
    {
        Linked_List output;
        Node *head1 = list.ret_head();
        Node *iter1 = head1;

        //        Lets push list first;
        do
        {
            output.push(iter1->data);
            iter1 = iter1->next;
        } while (iter1 != head1);

        Node *iter = head;
        do
        {
            output.push(iter->data);
            iter = iter->next;
        } while (iter != head);

        return output;
    }

    Node *ret_head()
    {
        return head;
    }
};

int main()
{

    Linked_List list1;
    list1.push(5);
    list1.push(10);
    list1.push(11);

    cout << "List 1: ";

    list1.display();

    cout << endl;

    Linked_List list2;
    list2.push(7);
    list2.push(12);
    list2.push(15);

    cout << "List 2: ";

    list2.display();

    cout << endl;

    cout << "After Concat: ";

    Linked_List concat_list = list2.concat(list1);

    concat_list.display();
    cout << endl;
}
