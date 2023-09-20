#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *right, *down;
    TreeNode(int d)
    {
        data = d;
        right = down = NULL;
    }
};
void show_2d_list(TreeNode *head)
{
    TreeNode *right_ptr, *down_ptr = head;
    while (down_ptr)
    {
        right_ptr = down_ptr;
        while (right_ptr)
        {
            cout << right_ptr->data << " ";
            right_ptr = right_ptr->right;
        }
        cout << endl;
        down_ptr = down_ptr->down;
    }
}
TreeNode *make_2d_list(int mat[][3], int i, int j, int m, int n)
{
    if (i > n - 1 || j > m - 1)
        return NULL;
    TreeNode *temp = new TreeNode(mat[i][j]);
    temp->right = make_2d_list(mat, i, j + 1, m, n);
    temp->down = make_2d_list(mat, i + 1, j, m, n);
    return temp;
}
int main()
{
    int m = 3, n = 3;
    int mat[][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}};
    TreeNode *head = make_2d_list(mat, 0, 0, m, n);
    show_2d_list(head);
}
