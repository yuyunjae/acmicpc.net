#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > map[50001]; // map[start] = <value, end>
bool visit[50001];

int main(void)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int N, M, st, en, val, ans = -1;
    pair<int, int> barn; 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> st >> en >> val;
        map[st].emplace_back(val, en);
        map[en].emplace_back(val, st);
    }
    pq.push(make_pair(0, 1));
    while (!pq.empty())
    {
        barn = pq.top();
        pq.pop();
        visit[barn.second] = true;

        // cout <<  "\n" << barn.first << " " << barn.second << endl;
        if (barn.second == N)
        {
            ans = barn.first;
            break ;
        }
        for (auto i : map[barn.second])
        {
            if (!visit[i.second])
                pq.push(make_pair(i.first + barn.first, i.second));
        }
    }
    cout << ans;
}