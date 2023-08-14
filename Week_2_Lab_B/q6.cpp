#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
class linked_list
{

    struct node *head;

public:
    void insert(char new_data)
    {
        struct node *new_node = new node;
        new_node->data = new_data;
        new_node->next = head;
        head = new_node;
    }
    void display()
    {
        struct node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    linked_list()
    {
        head = NULL;
    }

    void del(int pos)
    {
        struct node *ptr;
        ptr = head;
        if (pos == 0)
        {
            head = ptr->next;
        }
        else
        {
            for (int i = 0; i < pos - 1; i++)
            {
                ptr = ptr->next;
            }
            struct node *ptr1, *ptr_delete;

            ptr_delete = ptr->next;

            ptr1 = ptr;
            for (int i = 0; i < 2; i++)
            {
                ptr1 = ptr1->next;
                if (ptr1 == NULL)
                {
                    break;
                }
            }
            ptr->next = ptr1;

            delete (ptr_delete);
        }
    }

    void vowel_cleanup()
    {
        struct node *ptr = new node;
        ptr = head;
        int cnt = 0;
        while (ptr != NULL)
        {
            //            cout<<ptr->data;
            if (ptr->data == 'a' || ptr->data == 'e' || ptr->data == 'i' || ptr->data == 'o' || ptr->data == 'u' || ptr->data == 'A' || ptr->data == 'E' || ptr->data == 'I' || ptr->data == 'O' || ptr->data == 'U')
            {
                cout << "POS: " << cnt << endl;
                this->del(cnt);
                cnt--;
            }
            cnt++;
            ptr = ptr->next;
        }
    }
};
int main()
{
    linked_list list;
    string str;

    cout << "Kindly Enter a String: ";
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        list.insert(char(str[i]));
    }

    cout << endl;

    list.display();
    cout << endl;

    //    list.del(0);
    list.vowel_cleanup();
    cout << endl;

    list.display();
    cout << endl;
}
