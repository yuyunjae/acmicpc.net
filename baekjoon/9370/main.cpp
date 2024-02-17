#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>

#define MAXI 1000000000

using namespace std;

int main(void)  50%에서 메모리 초과가 난다... p_queue에 너무 많이 들어가는듯.
{
    int T, n, m, t, s, g, h, a, b, d, dum, wei, not_visit, pos, val;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<pair<int, int> > road[2001]; // wei, dest
        priority_queue<tuple<int, bool, int>, vector<tuple<int, bool, int> >, greater<tuple<int, bool, int> > > p_queue; // {wei, not_visit, pos}
        vector<int> ans;
        int visit[2001];
        bool throu[2001];

        cin >> n >> m >> t >> s >> g >> h;
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b >> d;
            road[a].emplace_back(d, b);
            road[b].emplace_back(d, a);
        }
        for (int j = 0; j < t; j++)
        {
            cin >> val;
            ans.push_back(val);
        }
        for (int j = 1; j <= n; j++)
        {
            visit[j] = MAXI;
            throu[j] = 0;
        }

        p_queue.emplace(0, 1, s);
        visit[s] = 0;
        while (!p_queue.empty())
        {
            tie(wei, not_visit, pos) = p_queue.top();
            p_queue.pop();
            if (visit[pos] < wei)
                continue;
            if (!not_visit && visit[pos] == wei)
                throu[pos] = true;
            //cout << wei << ":" << !not_visit << ":" << pos << endl;
            for (auto r : road[pos])
            {
                if (visit[r.second] > wei + r.first)
                {
                    visit[r.second] = wei + r.first;
                    if (!not_visit || (pos == g && r.second == h) || (pos == h && r.second == g))
                    {
                        p_queue.emplace(visit[r.second], 0, r.second);
                        //cout << "1:" << visit[r.second] << "->0->" << r.second << endl;
                    }
                    else
                    {
                        //cout << "2:" << visit[r.second] << "->1->" << r.second << endl;
                        p_queue.emplace(visit[r.second], 1, r.second);
                    }
                }
                else if (visit[r.second] == wei + r.first && (!not_visit || (pos == g && r.second == h) || (pos == h && r.second == g)))
                {
                    p_queue.emplace(visit[r.second], 0, r.second);
                    //cout << "3:" << visit[r.second] << "->0->" << r.second << endl;
                }
            }
        }
        sort(ans.begin(), ans.end());
        for (auto k : ans)
        {
            if (throu[k])
                cout << k << " ";
        }
        cout << '\n';
    }
}