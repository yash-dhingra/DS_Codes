#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class linked_list
{
    node *ptr, *head, *tail;

public:
    void push(int data)
    {
        node *new_node = new node;
        new_node->data = data;
        if (head == NULL)
        {
            new_node->next = NULL;
            tail = new_node;
            head = new_node;
            ptr = new_node;
        }

        else
        {
            new_node->next = NULL;
            ptr->next = new_node;
            tail = new_node;
            ptr = new_node;
        }
    }

    linked_list()
    {
        head = NULL;
    }

    void display()
    {
        node *iter = head;
        while (iter != NULL)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
    }

    int len()
    {
        node *iter = head;
        int len_o = 0;
        while (iter != NULL)
        {
            //            cout << iter->data<<" ";
            iter = iter->next;
            len_o++;
        }
        return len_o;
    }

    void insert(int data, int pos)
    {
        node *iter = head;
        for (int i = 0; i < pos - 1; i++)
        {
            iter = iter->next;
        }

        node *iter2 = iter;

        iter2 = iter2->next;

        node *new_node = new node;
        new_node->data = data;
        new_node->next = iter2;
        iter->next = new_node;

        //        cout<<iter2->data<<" ";
    }

    void del(int pos)
    {

        if (pos == 0)
        {
            node *ptr = head;
            head = head->next;
            delete ptr;
        }
        else
        {
            node *iter = head;
            for (int i = 0; i < pos - 1; i++)
            {
                iter = iter->next;
            }
            node *iter2 = iter;
            iter2 = iter2->next;
            iter2 = iter2->next;
            delete iter->next;
            iter->next = iter2;
        }
    }

    linked_list selection_sort()
    {
        linked_list list_out;
        node *iter = head;
        int max_pos;

        while (this->len() != 0)
        {
            int max = head->data;
            int pos = 0;
            max_pos = 0;
            while (iter != NULL)
            {
                if (iter->data > max)
                {
                    max = iter->data;
                    max_pos = pos;
                }

                pos++;
                iter = iter->next;
            }
            cout << "Run Pos: " << max << endl;
            list_out.push(max);
            this->del(max_pos);
        }

        return list_out;
    }

    void swap()
    {
        int head_data = head->data;
        head->data = tail->data;
        tail->data = head_data;
    }
};

int main()
{

    linked_list list;
    list.push(3);
    list.push(6);
    list.push(2);
    list.push(1);
    list.push(-1);
    list.push(10);

    list.display();

    cout << "After Swapping: " << endl;

    list.swap();

    list.display();

    cout << endl;
}
