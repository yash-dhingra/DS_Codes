#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class stack
{

    struct node *top;

public:
    void insert(int new_data)
    {
        struct node *new_node = new node;
        new_node->data = new_data;
        new_node->next = top;
        top = new_node;
    }
    void display()
    {
        struct node *ptr;
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

    void pop()
    {
        top = top->next;
    }

    int present(int data)
    {
        node *ptr = top;
        while (ptr != NULL)
        {
            if (data == ptr->data)
                return 1;
            ptr = ptr->next;
        }
        return 0;
    }
};

void insert(stack hashtable[], int input)
{
    hashtable[input % 10].insert(input);
}

int present(stack hashtable[], int input)
{
    return hashtable[input % 10].present(input);
}

int main()
{
    stack hashtable[10];

    int list[20];
    for (int i = 0; i < 20; i++)
    {
        list[i] = (rand() % 100);
        insert(hashtable, list[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        cout << list[i] << " ";
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "\n"
             << i << ": " << endl;
        hashtable[i].display();
        cout << endl;
    }

    cout << endl
         << present(hashtable, 40) << endl;
}
