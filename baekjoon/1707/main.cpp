#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char visit[20001];
queue<pair<int, bool> > vertex;
vector<int> edge[20001];

bool    bfs(bool t)
{
    if (t == false)
        return (t);
    if (vertex.empty())
        return (t);
    
    int ver = vertex.front().first;
    bool color = vertex.front().second;
    vertex.pop();

    for (auto i : edge[ver])
    {
        if (!visit[i])
        {
            visit[i] = color + 1; // color == 1 -> 2 color == 0 -> 1
            vertex.push({i, -color + 1});
        }
        else if (visit[i] == 1 && color == 1)
            return (false);
        else if (visit[i] == 2 && color == 0)
            return (false);
    }
    return (bfs(t));
}

int main(void)
{
    int K, V, E, u, v, ans;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> V >> E;
        for (int j = 0; j < E; j++)
        {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans = 1;
        for (int i = 1; i <= V; i++)
        {
            if (!visit[i])
            {
                vertex.push({i, 0});
                visit[i] = 2;
                ans = min(ans, int(bfs(1)));
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";

        while (!vertex.empty())
            vertex.pop();
        for (int j = 0; j <= V; j++)
        {
            visit[j] = 0;
            edge[j].clear();
        }
    }
}