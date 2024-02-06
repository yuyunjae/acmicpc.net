#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[101];
queue<int> vertex;
bool visit[101];

void bfs()
{
    if (vertex.empty())
        return ;
    
    int val = vertex.front();
    vertex.pop();

    for (auto i : edge[val])
    {
        if (!visit[i])
        {
            visit[i] = true;
            vertex.push(i);
        }
    }
    bfs();
}

int main(void)
{
    int N, M, u, v, ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    visit[1] = true;
    vertex.push(1);
    bfs();
    for (int i = 2; i <= N; i++)
    {
        if (visit[i] == true)
            ans++;
    }
    cout << ans;
}