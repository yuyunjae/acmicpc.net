#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// priority_queue 정렬을 위한 사용자 정의 비교 함수를 사용할 때, 구조체 선언 후, 연산자 오버로딩..
struct Compare { 
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq; 
bool visit[10001];
vector<pair<int, int> > edge[10001];

int main(void)
{
    int V, E, a, b, cost;
    long long int ans = 0;
    pair<int, int> line;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> cost;
        edge[a].emplace_back(cost, b);
        edge[b].emplace_back(cost, a);
    }

    pq.emplace(0, a);
    while (!pq.empty())
    {
        line = pq.top();
        pq.pop();
        if (visit[line.second]) continue;
        visit[line.second] = true;
        ans += line.first;
        //cout << line.first << " " << line.second << endl;

        for (auto i : edge[line.second])
        {
            if (!visit[i.second])
                pq.push(i);
        }
    }
    cout << ans;
}
