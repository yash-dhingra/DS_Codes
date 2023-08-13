
#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
class linkedlist
{

    struct node *head;

public:
    void push(int data)
    {
        node *new_ptr = new node;
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            new_ptr->data = data;
            new_ptr->next = head;
            head->prev = new_ptr;
            new_ptr->prev = NULL;
            head = new_ptr;
        }
    }

    void insert(int data, int pos)
    {
        int cntr = 0;
        node *ptr = new node;
        ptr = head;
        while (ptr != NULL)
        {
            if (pos == cntr)
            {
                node *new_node = new node;
                new_node->data = data;
                new_node->prev = ptr->prev;
                new_node->next = ptr;
                ptr->prev->next = new_node;
            }
            ptr = ptr->next;
            cntr++;
        }
    }

    void display()
    {
        node *ptr = new node;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    linkedlist()
    {
        head = NULL;
    }

    void del_end()
    {
        node *ptr = new node;
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
    }

    int len()
    {
        node *ptr = new node;
        ptr = head;
        int len1 = 0;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            len1++;
        }
        return len1;
    }

    void swap()
    {
        node *tail = new node;
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        node *ptr = head;

        //        int head_data=ptr->data;
        //
        //        ptr->data=tail->data;
        //        tail->data=head_data;
        //
        //        ptr=ptr->next;
        //        tail=tail->prev;
        //
        //
        //        cout << ptr->data<<endl<<tail->data;
        //
        //        head_data=ptr->data;
        //
        //        ptr->data=tail->data;
        //        tail->data=head_data;

        //        ////////////////////////////

        int head_data;

        //        while(ptr->next!=tail->prev){
        //            int head_data=ptr->data;
        //
        //            ptr->data=tail->data;
        //            tail->data=head_data;
        //
        //            ptr=ptr->next;
        //            tail=tail->prev;
        //
        //            cout<<"runn\n";
        //        }

        for (int i = 0; i < (this->len()) / 2; i++)
        {
            int head_data = ptr->data;

            ptr->data = tail->data;
            tail->data = head_data;
            ptr = ptr->next;
            tail = tail->prev;
            cout << "runn\n";
        }
    }
};
int main()
{
    linkedlist list;

    for (int i = 8; i > 0; i--)
    {
        list.push(i);
    }

    list.display();

    cout << endl;

    //    list.insert(0, 1);
    //    list.del_end();
    list.swap();
    cout << "\n";

    list.display();

    cout << endl;
}
