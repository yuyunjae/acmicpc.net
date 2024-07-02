/* 
처음에 priority_queue로 하려고 했는데 어처피 count 횟수가 적은 것이 queue 앞에 위치하면 되는 것이기 때문에, 그냥 bfs를 사용하면 queue로 해결하는 것이 더 좋다.
bfs + queue (그래프에서 보통 가중치가 없는 최대, 최솟값을 구할 떄)
priority_queue (dijkstra와 같이 그래프에 가중치가 있을 때 주로 사용)
이번 문제는 state위치도 중요하지만, 결국 가중치는 count횟수로, 1로 일정하므로 queue라고 빠르게 생각하고 bfs로 푸는 것이 좋다.
*/
#include <iostream>
#include <queue>

using namespace std;

int map[101];
bool visit[100];

int bfs()
{
    int count, state, curr_state;
    queue<pair<int, int> > que;

    que.push(make_pair(0, 1));
    while (!que.empty())
    {
        count = que.front().first;
        state = que.front().second;
        que.pop();

        for (int i = 1; i <= 6; i++)
        {
            curr_state = state + i;
            if (curr_state == 100)
                return (count + 1);
            else if (map[curr_state] && !visit[curr_state])
            {
                visit[curr_state] = true;
                curr_state = map[curr_state];
            }
            if (!visit[curr_state])
            {
                visit[curr_state] = true;
                que.push(make_pair(count + 1, curr_state));
            }
        }
    }
}

int main(void)
{
    int N, M, from, to;

    cin >> N >> M;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < N + M; i++)
    {
        cin >> from >> to;
        map[from] = to;
    }
    cout << bfs();
}
