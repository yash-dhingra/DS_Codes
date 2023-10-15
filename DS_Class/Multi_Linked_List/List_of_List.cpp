#include <iostream>
#include <cstdlib>
using namespace std;

struct Node2
{
    int data;
    Node2 *rp;
};
struct Node1
{
    int data;
    Node2 *rp;
    Node1 *dp;
};

class Multi_Linked_List
{
    Node1 *head;

public:
    void innit(int m, int n)
    {
        head = new Node1;
        Node1 *ptr = head;
        for (int i = 0; i < m - 1; i++)
        {
            Node1 *new_node1 = new Node1;
            new_node1->data = 0;
            new_node1->dp = NULL;
            new_node1->rp = NULL;
            ptr->dp = new_node1;
            ptr = ptr->dp;
        }

        ptr = head;

        for (int i = 0; i < m; i++)
        {
            Node2 *new_node2 = new Node2;
            new_node2->data = 1;
            new_node2->rp = NULL;
            ptr->rp = new_node2;
            Node2 *ptr2 = new_node2;
            for (int j = 0; j < n - 1; j++)
            {
                Node2 *new_node_2 = new Node2;
                new_node_2->data = 1;
                new_node_2->rp = NULL;
                ptr2->rp = new_node_2;
                ptr2 = ptr2->rp;
            }
            ptr = ptr->dp;
        }
    }
    void display_column()
    {
        Node1 *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            Node2 *ptr2 = ptr->rp;
            while (ptr2 != NULL)
            {
                cout << ptr2->data << " ";
                ptr2 = ptr2->rp;
            }
            ptr = ptr->dp;
            cout << endl;
        }
    }
};

int main()
{
    Multi_Linked_List list;
    list.innit(5, 5);
    list.display_column();
}
