#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> edge[1001];
queue<int> vertex_bfs;
stack<int> vertex_dfs;
bool visit[1001];

void    dfs()
{
    if (vertex_dfs.empty())
        return ;

    int ver = vertex_dfs.top();
    vertex_dfs.pop();

    for (auto i: edge[ver])
    {
        if (!visit[i])
        {
            visit[i] = true;
            cout << " " << i;
            vertex_dfs.push(i);
            dfs();
        }
    }
}

void    bfs()
{
    if (vertex_bfs.empty())
        return ;
    
    int ver = vertex_bfs.front();
    vertex_bfs.pop();

    for (auto i : edge[ver])
    {
        if (!visit[i])
        {
            visit[i] = true;
            cout << " " << i;
            vertex_bfs.push(i);
        }
    }
    bfs();
}

int main(void)
{
    int N, M, V, u, v;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    for (int i = 0; i < M;i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
        sort(edge[i].begin(), edge[i].end());
    
    visit[V] = true;
    vertex_dfs.push(V);
    cout << V;
    dfs();
    cout << "\n";
    for (int i = 1; i <= N; i++)
        visit[i] = false;
    visit[V] = true;
    vertex_bfs.push(V);
    cout << V;
    bfs();
}