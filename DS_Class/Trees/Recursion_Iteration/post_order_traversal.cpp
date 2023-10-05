#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *rp, *lp;
};

struct stack_node
{
    Node *data;
    stack_node *next;
};

class queue
{
    stack_node *head, *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(Node *data)
    {
        stack_node *new_ptr = new stack_node;
        new_ptr->data = data;
        new_ptr->next = NULL;
        if (tail == NULL)
        {
            tail = new_ptr;
            head = tail;
        }

        else
        {
            tail->next = new_ptr;
            tail = new_ptr;
        }
    }

    void display()
    {
        stack_node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    Node *pop()
    {
        stack_node *ptr = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        return ptr->data;
    }

    int is_empty()
    {
        if (head == NULL)
            return 1;
        return 0;
    }
};

class Tree
{
    Node *head;
    queue qu;

public:
    Tree()
    {
        head = NULL;
    }

    void insert_list(int array[], int len)
    {
        head = new Node;
        head->data = array[0];
        head->rp = NULL;
        head->lp = NULL;
        qu.insert(head);
        int i = 1;
        while (qu.is_empty() != 1 && i <= len)
        {
            Node *ptr = qu.pop();
            int left_node_index = (i * 2) - 1;
            int right_node_index = (i * 2);
            Node *left_ptr = NULL;
            Node *right_ptr = NULL;
            if (array[left_node_index] != -1 && left_node_index < len)
            {
                left_ptr = new Node;
                cout << "LN: " << array[left_node_index] << endl;
                left_ptr->data = array[left_node_index];
                left_ptr->rp = NULL;
                left_ptr->lp = NULL;
                qu.insert(left_ptr);
            }
            ptr->lp = left_ptr;
            if (array[right_node_index] != -1 && right_node_index < len)
            {
                right_ptr = new Node;
                cout << "RN: " << array[right_node_index] << endl;
                right_ptr->data = array[right_node_index];
                right_ptr->rp = NULL;
                right_ptr->lp = NULL;
                qu.insert(right_ptr);
            }
            ptr->rp = right_ptr;
            //            cout <<"run i:"<<qu.is_empty()<<"\n";
            i++;
        }
    }
    void post_print_helper(Node *ptr)
    {
        if (ptr == NULL)
            return;

        post_print_helper(ptr->lp);
        post_print_helper(ptr->rp);
        cout << ptr->data << " ";
    }
    void post_print()
    {
        post_print_helper(head);
    }
};

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(array) / sizeof(array[0]);
    Tree tree;
    tree.insert_list(array, len);
    cout << "\nlets Print: ";
    tree.post_print();
}
