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

    void del_dupli(Node *del)
    {
        Node *iter = del;
        Node *iter_prev = del;
        Node *iter_forw;
        iter = iter->next;
        while (iter != del)
        {
            if (iter->data == del->data)
            {
                iter_forw = iter->next;
                iter_prev->next = iter_forw;
                //                delete iter;
                if (iter == head)
                {
                    head = iter_forw;
                    break;
                }
            }
            iter_prev = iter;
            iter = iter->next;
        }
    }

    void delete_duplicate()
    {
        Node *iter = head;
        do
        {
            //            cout<< "exec"<<iter->data;
            this->del_dupli(iter);
            iter = iter->next;
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

    int len()
    {
        int le = 0;
        Node *iter = head;
        do
        {
            iter = iter->next;
            le++;
        } while (iter != head);
        return le;
    }

    void split()
    {

        Node *head1, *head2, *tail1, *tail2;
        head1 = head;
        tail1 = head1;
        for (int i = 0; i < (this->len() / 2) - 1; i++)
        {
            tail1 = tail1->next;
        }
        head2 = tail1->next;
        tail1->next = head1;
        tail2 = head2;
        Node *prev_head;
        while (tail2 != head)
        {
            prev_head = tail2;
            tail2 = tail2->next;
        }

        prev_head->next = head2;

        //        Printing of First Circular linked list....

        cout << "List 1: " << endl;
        Node *iter = head1;
        do
        {
            cout << iter->data << " ";
            iter = iter->next;
        } while (iter != head1);

        //        Printing of Second Circular linked list....

        cout << endl
             << "List 2: " << endl;
        iter = head2;
        do
        {
            cout << iter->data << " ";
            iter = iter->next;
        } while (iter != head2);
    }
};

int main()
{

    Linked_List list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);

    list.display();

    cout << endl;

    list.split();

    cout << endl;
}
