#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > edge;
int visit[100001];
int visit_seq;

int binary_search_left(int start)
{
    int left = 0, right = edge.size() - 1, mid;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (edge[mid].first >= start)
            right = mid;
        else
            left = mid + 1;
    }
    return (right);
}

void    dfs(int start)
{
    if(visit[start])
        return ;
    visit[start] = visit_seq++;

    int i;
    for (i = binary_search_left(start); edge[i].first == start; i++)
        dfs(edge[i].second);
}

bool cmp(pair<int, int> a, pair<int, int>b)
{
    if (a.first == b.first)
        return (a.second < b.second);
    else
        return (a.first < b.first);
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
        edge.push_back({u, v});
        edge.push_back({v, u});
    }
    sort(edge.begin(), edge.end(), cmp);
    visit_seq = 1;
    dfs(R);

    for (int i = 1; i <= N; i++)
        cout << visit[i] << "\n";
}