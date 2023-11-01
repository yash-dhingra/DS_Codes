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

// Stack Begins
class stack
{

    struct stack_node *top;

public:
    void push(Node *new_data)
    {
        stack_node *new_node = new stack_node;
        new_node->data = new_data;
        new_node->next = top;
        top = new_node;
    }
    void display()
    {
        struct stack_node *ptr;
        ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data->data << " ";
            ptr = ptr->next;
        }
    }
    stack()
    {
        top = NULL;
    }

    Node *pop()
    {
        stack_node *ptr = top;
        top = top->next;
        return ptr->data;
    }

    int is_empty()
    {
        if (top == NULL)
            return 1;
        return 0;
    }
};
// Stack Ends

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
            cout << ptr->data->data << " ";
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
stack path;
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
            if (array[left_node_index] != 0 && left_node_index < len)
            {
                left_ptr = new Node;
                cout << "LN: " << array[left_node_index] << endl;
                left_ptr->data = array[left_node_index];
                left_ptr->rp = NULL;
                left_ptr->lp = NULL;
                qu.insert(left_ptr);
            }
            ptr->lp = left_ptr;
            if (array[right_node_index] != 0 && right_node_index < len)
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

    void level_print()
    {
        queue stak;
        Node *ptr = head;
        stak.insert(head);
        while (stak.is_empty() != 1 && ptr != NULL)
        {
            ptr = stak.pop();
            cout << ptr->data << " ";
            if (ptr->lp != NULL)
            {
                stak.insert(ptr->lp);
            }
            if (ptr->rp != NULL)
            {
                stak.insert(ptr->rp);
            }
        }
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

    void pre_print_helper(Node *ptr)
    {
        if (ptr == NULL)
            return;
        cout << ptr->data << " ";
        pre_print_helper(ptr->lp);
        pre_print_helper(ptr->rp);
    }
    void pre_print()
    {
        pre_print_helper(head);
    }

   

    // int max_sum_helper(Node *ptr){
    //     if(ptr->lp!=NULL && ptr->rp!=NULL){
    //         int l_sum=max_sum_helper(ptr->lp);
    //         int r_sum = max_sum_helper(ptr->rp);
    //         l_sum+=ptr->data;
    //         r_sum+=ptr->data;
    //         if(l_sum>=r_sum){
    //             path.push(ptr->lp);
    //             return l_sum;
    //         }
    //         else{
    //             path.push(ptr->rp);
    //             return r_sum;
    //         }
    //     }
    //     else{
    //         return ptr->data;
    //     }
    //     if(ptr->lp==NULL){
    //         int r_sum = max_sum_helper(ptr->rp);
    //         r_sum += ptr->data;
    //         path.push(ptr->rp);
    //         return r_sum;
    //     }
    //     if (ptr->rp == NULL)
    //     {
    //         int l_sum = max_sum_helper(ptr->lp);
    //         l_sum += ptr->data;
    //         path.push(ptr->lp);
    //         return l_sum;
    //     }
        
    // }

    int max_sum_helper(Node *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }

        int l_sum = max_sum_helper(ptr->lp);
        int r_sum = max_sum_helper(ptr->rp);

        int total_sum;
            // Compare the sums of left and right subtrees
        if (l_sum >= r_sum)
        {
            total_sum = l_sum  + ptr->data;
            path.push(ptr->lp);
        }
        else
        {
            total_sum = r_sum + ptr->data;
            path.push(ptr->rp);
        }

        return total_sum;
    }

    int max_sum(){
        return max_sum_helper(head);
        
    }
};

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 0, 0, 0, 10, 11, 12, 13, 0, 14, 15, 0, 16, 17};
    int len = sizeof(array) / sizeof(array[0]);
    Tree tree;
    tree.insert_list(array, len);

    cout << "\nLevel Print: ";
    tree.level_print();

    cout << "\n"<<"Max Sum: "<<tree.max_sum();
    cout << "\nPath: ";
    path.display();
}
