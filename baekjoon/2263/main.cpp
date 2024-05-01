#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct s_node
{
    int left;
    int right;
} node;

node tree[100001];
int inorder[100001];
int postorder[100001];

void    find_tree(int left, int right, int root)
{
    int i = left;
    // 미완
    if (right - left == -1) // 자식 없는 경우
        return ;
    if (right == left) // 자식 하나 있는 경우
    {
        tree[postorder[root]].left = left;
        return ;
    }
    if (right - left == 1) // 좌우 자식 모두 있는 경우
    {
        tree[postorder[root]].right = postorder[right];
        tree[postorder[root]].left = postorder[left];
        return ; 
    }
    while (inorder[i] != postorder[root])
        i++;
    tree[postorder[root]].right = postorder[root - 1];
    tree[postorder[root]].left = postorder[i - 1];
    find_tree(left, i - 2, i - 1);
    find_tree(i, root - 2, root - 1);
}

void    print_tree(int root)
{
    if (!root)
        return ;
    cout << root << " ";
    print_tree(tree[root].left);
    print_tree(tree[root].right);
}

int main(void) //미완 ...
{
    int n, val;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) // inorder (left_child, root, right_child)
    {
        cin >> inorder[i];
    }
    for (int i = 1; i <= n; i++) // postorder (left_child, right_child, root)
    {
        cin >> postorder[i];
    }
    find_tree(1, n - 1, n);
    print_tree(postorder[n]);
}