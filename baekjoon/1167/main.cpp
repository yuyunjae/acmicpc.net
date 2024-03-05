// sol 76m/s not bfs.. use dfs https://blog.myungwoo.kr/112 참고 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > tree[100001]; // {node, distance}
int max_distance, s;
bool visit[100001];

void    dfs(int start, int distance, int *node)
{
    for (auto i : tree[start])
    {
        if (!visit[i.first])
        {
            visit[i.first] = true;
            dfs(i.first, distance + i.second, node);
            visit[i.first] = false;
        }
    }
    if (distance > max_distance)
    {
        max_distance = distance;
        *node = start;
    }
}

int main(void)
{
    int V, e, d, dis = 0, first = 0, last = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V;
    for (int i = 1; i <= V; i++)
    {
        cin >> s;
        while (1)
        {
            cin >> e;
            if (e == -1)
                break ;
            cin >> d;
            tree[s].emplace_back(e, d);
        }
    }
    visit[s] = true;
    dfs(s, 0, &first);
    for (int i = 0; i <= V; i++)
        visit[i] = false;
    visit[first] = true;
    dfs(first, 0, &last);
    cout << max_distance;
}