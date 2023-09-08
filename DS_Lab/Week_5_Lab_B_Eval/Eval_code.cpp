#include <iostream>
using namespace std;

struct Node
{
    int data;
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

    void push(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
    }

    int len()
    {
        int count = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    Linked_List sum(Linked_List list1)
    {
        Linked_List out;
        // Extract Nums

        int num1 = 0, num2 = 0;
        int temp_base = 1;

        // Local Number

        Node *ptr = head;
        while (ptr != NULL)
        {
            num1 += (temp_base * ptr->data);
            ptr = ptr->next;
            temp_base *= 10;
        }

        // cout<<num1<<"Number";

        ptr = list1.ret_head();

        temp_base = 1;
        while (ptr != NULL)
        {
            num2 += (temp_base * ptr->data);
            ptr = ptr->next;
            temp_base *= 10;
        }

        // cout<<num2<<"Number";

        int out_sum = num1 + num2;

        // int out_sum_temp=out_sum;
        int cnt = 0;
        while (out_sum != 0)
        {
            cnt++;
            out.push(out_sum % 10);
            out_sum = out_sum / 10;
        }

        // out.display();
        return out;
    }

    Node *ret_head()
    {
        return head;
    }
};

int main()
{
    Linked_List stack2;
    Linked_List stack1;

    int num1, num2, tmp;

    cout << "Numbers of Nodes in linked list 1: ";
    cin >> num1;

    for (int i = 0; i < num1; i++)
    {
        cin >> tmp;
        stack1.push(tmp);
    }

    cout << "Numbers of Nodes in linked list 2: ";
    cin >> num2;

    for (int i = 0; i < num2; i++)
    {
        cin >> tmp;
        stack2.push(tmp);
    }

    stack1.sum(stack2).display();
}