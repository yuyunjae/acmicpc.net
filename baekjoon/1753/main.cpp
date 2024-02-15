#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define INF 4000000

using namespace std;

bool visit[20001];
int ans[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> vertex;
vector<pair<int, int> > edge[20001]; // edge[vertex_from] = {weight, vertex_dest};

void    dijkstra()
{
    int wei, ver;

    while (!vertex.empty())
    {
        while (!vertex.empty())
        {
            tie(wei, ver) = vertex.top();
            vertex.pop();
            if (vertex.empty() && visit[ver])
                return ;
            else if (!visit[ver])
            {
                visit[ver] = true;
                break ;
            }
        }
        for (auto i : edge[ver])
        {
            //cout << i.second;
            if (ans[i.second] > wei + i.first)
            {
                ans[i.second] = wei + i.first;
                vertex.emplace((wei + i.first), i.second);
                //cout << vertex.top().first << ":" << vertex.top().second << endl;
            }
        }
    }
}

int main(void)
{
    int V, E, K, u, v, w;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edge[u].emplace_back(w, v);
    }
    for (int i = 0; i <= V; i++)
        ans[i] = INF;
    vertex.emplace(0, K);
    ans[K] = 0;
    dijkstra();
    for (int i = 1; i <= V; i++)
    {
        if (ans[i] == INF)
            cout << "INF\n";
        else
            cout << ans[i] << '\n';
    }
}