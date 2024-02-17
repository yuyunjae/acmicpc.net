#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAXI 1000000000

using namespace std;

void dijkstra(int s, int* visit, vector<pair<int, int>>* road)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p_queue; // {wei, not_visit, pos}
    int wei, pos;

    for (int i = 0; i < 2001; i++)
        visit[i] = MAXI;
    p_queue.emplace(0, s);
    visit[s] = 0;
    while (!p_queue.empty())
    {
        tie(wei, pos) = p_queue.top();
        p_queue.pop();
        for (auto i : road[pos])
        {
            if (visit[i.second] > wei + i.first)
            {
                visit[i.second] = wei + i.first;
                p_queue.emplace(visit[i.second], i.second);
            }
        }
    }
}

int main(void)
{
    int T, n, m, t, s, g, h, a, b, d, gh, val;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<pair<int, int> > road[2001]; // wei, dest
        vector<int> ans;
        int s_visit[2001];
        int g_visit[2001];
        int h_visit[2001];

        cin >> n >> m >> t >> s >> g >> h;
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b >> d;
            if ((a == g && b == h) || (a == h && b == g))
                gh = d;
            road[a].emplace_back(d, b);
            road[b].emplace_back(d, a);
        }
        for (int j = 0; j < t; j++)
        {
            cin >> val;
            ans.push_back(val);
        }
        dijkstra(s, s_visit, road);       
        dijkstra(g, g_visit, road);
        dijkstra(h, h_visit, road);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < t; j++)
        {
            if (s_visit[ans[j]] == s_visit[g] + gh + h_visit[ans[j]])
                cout << ans[j] << " ";
            else if (s_visit[ans[j]] == s_visit[h] + gh + g_visit[ans[j]])
                cout << ans[j] << " ";
        }
        cout << '\n';
    }
}