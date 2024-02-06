#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> edge[100001];
queue<int> vertex;
int visit[100001];
int visit_seq;

void    bfs()
{
    int ver;

    if (vertex.empty())
        return ;
    ver = vertex.front();
    vertex.pop();
    
    for (auto i : edge[ver])
    {
        if (!visit[i])
        {
            visit[i] = visit_seq++;
            vertex.push(i);
        }
    }
    bfs();
}

int main(void)
{
    int N, M, R, u, v;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 0; i <= N; i++)
    {
        sort(edge[i].begin(), edge[i].end(), greater<int>());
    }
    // for (auto a : edge)
    // {
    //     cout << a.first << " " << a.second << endl;
    // }
    visit_seq = 1;
    vertex.push(R);
    visit[R]= visit_seq++;
    bfs();

    for (int i = 1; i <= N; i++)
        cout << visit[i] << "\n";
}