#include <iostream>

using namespace std;

int parent[201];
int way[1000];

int find_root(int a)
{
    if (parent[a] == a)
        return (a);
    return find_root(parent[a]);
}

int main(void)
{
    int N, M, dummy, root, my_root;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for (int i = 0; i < 201; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
    {
        my_root = find_root(i);
        for (int j = 1; j <= i; j++)
            cin >> dummy;
        
        for (int j = i + 1; j <= N; j++)
        {
            cin >> dummy;
            if (dummy)
            {
                root = find_root(j);
                if (my_root != root)
                    parent[root] = my_root;
            }
        }
    }

    if (M)
    {
        cin >> way[0];
        root = find_root(way[0]);
    }

    for (int i = 1; i < M; i++)
    {
        cin >> way[i];
        if (root != find_root(way[i]))
        {
            cout << "NO";
            return (0);
        }
    }
    cout << "YES";
    return (0);
}