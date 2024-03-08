#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct s_node
{
    char    value;
    int     left_child;
    int     right_child;
} node;

node tree[26];
stack<int> visit;

void    visit_clear()
{
    while (!visit.empty())
        visit.pop();
    return ;
}

void    f_dfs() // preorder-traversal (전위 순회)
{
    int val;

    if (visit.empty())
        return ;
    val = visit.top();
    visit.pop();

    if (tree[val].left_child != -1)
    {
        visit.push(tree[val].left_child);
        cout << tree[tree[val].left_child].value;
        f_dfs();
    }
    if (tree[val].right_child != -1)
    {
        visit.push(tree[val].right_child);
        cout << tree[tree[val].right_child].value;
        f_dfs();
    }
}

void    m_dfs() // inorder-traversal (중위 순회)
{
    int val;

    if (visit.empty())
        return ;
    val = visit.top();
    visit.pop();

    if (tree[val].left_child != -1)
    {
        visit.push(tree[val].left_child);
        m_dfs();
    }
    cout << tree[val].value;
    if (tree[val].right_child != -1)
    {
        visit.push(tree[val].right_child);
        m_dfs();
    }
}

void    l_dfs() // postorder-traversal (후위 순회)
{
    int val;

    if (visit.empty())
        return ;
    val = visit.top();
    visit.pop();

    if (tree[val].left_child != -1)
    {
        visit.push(tree[val].left_child);
        l_dfs();
    }
    if (tree[val].right_child != -1)
    {
        visit.push(tree[val].right_child);
        l_dfs();
    }
    cout << tree[val].value;
}

int main(void)
{
    int     N;
    char    n, l, r;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n >> l >> r;
        tree[n - 'A'].value = n;
        if (isalpha(l))
            tree[n - 'A'].left_child = l - 'A';
        else
            tree[n - 'A'].left_child = -1;
        if (isalpha(r))
            tree[n - 'A'].right_child = r - 'A';
        else
            tree[n - 'A'].right_child = -1;     
    }
    visit.push(0);
    cout << 'A';
    f_dfs();
    cout << '\n';
    visit_clear();
    visit.push(0);
    m_dfs();
    cout << '\n';
    visit_clear();
    visit.push(0);
    l_dfs();
}