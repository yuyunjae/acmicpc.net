#include <iostream>
#include <queue>
#include <tuple>

#define INF 100001

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p_queue;
int visit[100001];

void    dijkstra(int K)
{
    int wei, pos;

    while (!p_queue.empty())
    {
        tie(wei, pos) = p_queue.top();
        //cout << wei << ":" << pos << endl;
        p_queue.pop();
        if (pos == K)
        {
            cout << wei;
            exit(0);
        }
        if (pos - 1 >= 0 && visit[pos - 1] > wei + 1)
        {
            visit[pos - 1] = wei + 1;
            p_queue.emplace(visit[pos - 1], pos - 1);
        }
        if (pos + 1 <= 100000 && visit[pos + 1] > wei + 1)
        {
            visit[pos + 1] = wei + 1;
            p_queue.emplace(visit[pos + 1], pos + 1);
        }
        if (pos < K && pos * 2 <= 100000 && visit[pos * 2] > wei)
        {
            visit[pos * 2] = wei;
            p_queue.emplace(visit[pos * 2], pos * 2);
        }
    }
}

int main(void)
{
    int N, K;

    cin >> N >> K;
    for (int i = 0; i < INF; i++)
        visit[i] = INF;
    p_queue.emplace(0, N);
    visit[N] = 0;
    dijkstra(K);
}