#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
class stack
{

    struct Node *top;

public:
    void insert(int new_data)
    {
        struct Node *new_Node = new Node;
        new_Node->data = new_data;
        new_Node->next = top;
        top = new_Node;
    }
    void display()
    {
        struct Node *ptr;
        ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    stack()
    {
        top = NULL;
    }

    void reverse()
    {
        Node *ptr;
        int length = this->len();
        for (int i = 0; i < length; i++)
        {
            ptr = top;
            for (int j = 0; j < length - i - 1; j++)
            {
                ptr = ptr->next;
            }
            cout << ptr->data << " ";
        }
    }

    int len()
    {
        struct Node *ptr;
        ptr = top;
        int len = 0;
        while (ptr != NULL)
        {
            //            cout << ptr->data << " ";
            ptr = ptr->next;
            len++;
        }
        return len;
    }
};
int main()
{
    stack list;
    for (int i = 0; i < 10; i++)
    {
        list.insert(rand() % 10);
    }

    list.display();

    cout << "\nafter reversal: " << endl;
    list.reverse();
}
