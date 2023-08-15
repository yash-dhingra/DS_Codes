#include <iostream>
using namespace std;

struct Node
{
    int num, coeff;
    Node *next;
};

class Linked_List
{
    Node *head;

public:
    Linked_List()
    {
        head = NULL;
    }

    void push(int num, int coeff)
    {
        Node *new_node = new Node;
        new_node->num = num;
        new_node->coeff = coeff;
        if (head == NULL)
        {

            head = new_node;
            //            cout << head->num<<"exec";
            new_node->next = NULL;
        }

        else
        {
            new_node->next = head;
            head = new_node;
        }
    }

    void display()
    {
        Node *iter = head;
        cout << "{ ";
        while (iter != NULL)
        {
            cout << iter->num << "x^" << iter->coeff << "+";
            iter = iter->next;
        }
        cout << " }\n";
    }

    Linked_List multiply(Linked_List list1)
    {
        Node *iter = head;
        Node *iter1 = list1.ret_head();
        Linked_List list_out;
        // Initialize the array..
        list_out.initialize(this->max() + list1.max());

        while (iter != NULL)
        {
            iter1 = list1.ret_head();
            while (iter1 != NULL)
            {
                int num = (iter->num) * (iter1->num);
                int coeff = iter->coeff + iter1->coeff;

                //                cout <<"Num: "<<coeff<<endl;
                list_out.insert(num, coeff);

                iter1 = iter1->next;
            }

            iter = iter->next;
        }
        return list_out;
    }

    int max()
    {
        Node *iter = head;
        int ma = iter->coeff;
        while (iter != NULL)
        {
            if (iter->coeff > ma)
            {
                ma = iter->coeff;
            }
            iter = iter->next;
        }

        return ma;
    }

    void insert(int num, int coeff)
    {
        Node *iterr = head;

        while (iterr != NULL)
        {
            if (iterr->coeff == coeff)
            {
                iterr->num = iterr->num + num;
                //                cout << "NUM"<<iterr->num;
                break;
            }
            iterr = iterr->next;
        }
    }

    void initialize(int deg)
    {
        for (int i = 0; i <= deg; i++)
        {
            push(0, i);
        }
    }

    Node *ret_head()
    {
        return head;
    }
};

int main()
{
    Linked_List list;
    list.push(4, 2);
    list.push(2, 1);
    list.display();

    Linked_List list1;
    list1.push(4, 2);
    list1.push(2, 1);
    list1.display();

    Linked_List ll = list1.multiply(list);

    ll.display();
}
