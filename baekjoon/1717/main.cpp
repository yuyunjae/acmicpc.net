
#include <iostream>

using namespace std;

int parent[1000001];

int find_root(int a, int *level)
{
    *level = *level + 1;
    if (parent[a] == a) return (a);
    else return (find_root(parent[a], level));
}

void sum_arr(int a, int b)
{
    int a_level = 0, b_level = 0;
    a = find_root(a, &a_level);
    b = find_root(b, &b_level);
    if (a != b)
    {
        if (a_level >= b_level)
            parent[b] = a;
        else
            parent[a] = b;
    }
}

int main(void)
{
    int n, m, option, a, b, a_root, b_root;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> option >> a >> b;
        if (option == 0)
            sum_arr(a, b);
        else
        {
            a_root = find_root(a, &option);
            b_root = find_root(b, &option);
            if (a_root == b_root)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}


/*
#include <iostream>

using namespace std;

int parent[1000001];

int find_root(int a)
{
    if (parent[a] == a) return (a);
    else 
    {
        parent[a] = find_root(parent[a]);
        return parent[a];
    }
}

void sum_arr(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if (a != b)
        parent[a] = b;
}

int main(void)
{
    int n, m, option, a, b, a_root, b_root;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> option >> a >> b;
        if (option == 0)
            sum_arr(a, b);
        else
        {
            a_root = find_root(a);
            b_root = find_root(b);
            if (a_root == b_root)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
*/