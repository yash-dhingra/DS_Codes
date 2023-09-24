#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
class stack
{

    struct node *top;

public:
    void push(char new_data)
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

    char *reverse_string(string str)
    {
        stack st;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            st.push(str[i]);
        }
        char ret[len];
        for (int i = 0; i < len; i++)
        {
            ret[i] = st.top->data;
            st.pop();
        }
        return ret;
    }
};
int main()
{
    stack list;

    cout << list.reverse_string("hello World") << endl;
}
