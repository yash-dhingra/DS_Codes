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

    int pop()
    {
        if (top != NULL)
        {
            int dat = top->data;
            top = top->next;
            return dat;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    int num_of_list;
    cout << "Kindly Enter the Number of List you'd like to have: ";
    cin >> num_of_list;

    stack array[num_of_list];
    int input = 0;
    cout << "Enter to -1 to stop data entry: ";
    for (int i = 0; i < num_of_list; i++)
    {
        input = 0;
        cout << "Enter data of " << i << " List: ";
        while (true)
        {
            cin >> input;
            if (input != -1)
            {
                array[i].insert(input);
            }
            else
            {
                break;
            }
            //            input==-1 ? break : array[i].insert(input);
        }
    }

    for (int i = 0; i < num_of_list; i++)
    {
        while (true)
        {
            int dat = array[i].pop();
            if (dat == -1)
                break;
            else
            {
                cout << dat << " ";
            }
        }
        cout << endl;
    }
}
