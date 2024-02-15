#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define INF 4000000

using namespace std;

int ans[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> vertex;
vector<pair<int, int> > edge[20001]; // edge[vertex_from] = {weight, vertex_dest};

void    dijkstra()
{
    int wei, ver;

    while (!vertex.empty())
    {
        tie(wei, ver) = vertex.top();
        vertex.pop();
        for (auto i : edge[ver])
        {
            if (ans[i.second] > wei + i.first)
            {
                ans[i.second] = wei + i.first;
                vertex.emplace((wei + i.first), i.second);
            }
        }
    }
}

void    clear(int N)
{
    for (int i = 0; i <= N; i++)
        ans[i] = INF;
    while (!vertex.empty())
        vertex.pop();
}

int main(void)
{
    int N, E, u, v, w, ver1, ver2, path[2];

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edge[u].emplace_back(w, v);
        edge[v].emplace_back(w, u);
    }
    cin >> ver1 >> ver2;

    clear(N);
    vertex.emplace(0, 1);
    ans[1] = 0;
    dijkstra();
    if (ans[ver1] == INF || ans[ver2] == INF)
    {
        cout << "-1";
        return (0);
    }
    path[0] = ans[ver1];
    path[1] = ans[ver2];

    clear(N);
    vertex.emplace(0, ver1);
    ans[ver1] = 0;
    dijkstra();
    if (ans[N] == INF || ans[ver2] == INF)
    {
        cout << "-1";
        return (0);
    }
    path[0] += ans[ver2];
    path[1] += ans[N];

    clear(N);
    vertex.emplace(0, ver2);
    ans[ver2] = 0;
    dijkstra();
    if (ans[N] == INF || ans[N] == ver1)
    {
        cout << "-1";
        return (0);
    }
    path[0] += ans[N];
    path[1] += ans[ver1];
    cout << min(path[0], path[1]);
}