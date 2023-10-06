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
    Node *push_bst_helper(Node *ptr, int data)
    {
        if (ptr == NULL)
        {
            ptr = new Node;
            ptr->data = data;
            ptr->rp = ptr->lp = NULL;
            //            cout << "Run";
        }
        else if (ptr->data < data)
        {
            ptr->rp = push_bst_helper(ptr->rp, data);
        }
        else if (ptr->data > data)
        {
            ptr->lp = push_bst_helper(ptr->lp, data);
        }
        return ptr;
    }

    void push_bst(int data)
    {
        push_bst_helper(head, data);
    }

    void in_print_helper(Node *ptr)
    {
        if (ptr == NULL)
            return;

        in_print_helper(ptr->lp);
        cout << ptr->data << " ";
        in_print_helper(ptr->rp);
    }
    void in_print()
    {
        in_print_helper(head);
    }
};

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;
    int len = sizeof(array) / sizeof(array[0]);
    Tree tree;
    int arr[] = {1};
    tree.insert_list(arr, 1);
    for (int i = 0; i < 10; i++)
    {
        tree.push_bst(array[i]);
    }
    cout << endl;
    //    cout << "Number of Leaf Nodes Present in the Tree: " << tree.count_leaf_node() << endl;
    tree.in_print();
}
