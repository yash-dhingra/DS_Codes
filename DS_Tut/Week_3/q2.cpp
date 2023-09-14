#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{

public:
    Node *ptr, *head;
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

int equal_list(Linked_List list1, Linked_List list2, int len)
{
    Node *head1 = list1.head;
    Node *head2 = list2.head;
    Node *iter1 = head1, *iter2 = head2;
    Node *iter1_main = head1;
    int flag = 1;

    for (int k = 0; k < len; k++)
    {
        iter1 = iter1_main;
        flag = 1;
        int in = 0;
        iter2 = head2;
        //        cout << "List1: "<<iter1->data<<" List2: "<<iter2->data<<endl;
        if (iter1_main->data == iter2->data)
        {

            for (int i = 0; i < len; i++)
            {
                //                cout << "List1: "<<iter1->data<<"List2: "<<iter2->data<<endl;
                if (iter1->data != iter2->data)
                {
                    flag = 0;
                    in = 0;
                    break;
                }
                in = 1;
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
        }
        else
        {
            iter1_main = iter1_main->next;
        }
        if (flag == 1 && in == 1)
        {
            return 1;
        }
        //        cout << iter1_main->data<<endl;
    }

    return 0;
}

int main()
{

    Linked_List list1;
    list1.push(5);
    list1.push(10);
    list1.push(11);

    Linked_List list2;
    list2.push(11);
    list2.push(5);
    list2.push(10);

    cout << equal_list(list1, list2, 3) << endl;
}
