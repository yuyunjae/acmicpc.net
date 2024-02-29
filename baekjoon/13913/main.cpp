#include <iostream>
#include <queue>
#include <stack>

#define MAXI 1e5

using namespace std;
int visit[200000]; // viist으로 이전 경로를 저장했는데, 사실 그냥 char visit[200000]; 해놓고 따로 int before[200000]; 사용하면, 공간은 좀 더 쓰더라도 오류를 방지하기 쉬울듯..

void bfs(int N, int K)
{
    int state, time, time_max = MAXI;
    queue<pair<int, int> > move; // {state, time}
    stack<int> ans;
    move.emplace(N, 0);
    while (!move.empty())
    {
        state = move.front().first;
        time = move.front().second;
        move.pop();
        if (state == K)
            break ;
        if (state < K && !visit[state + 1])
        {
            visit[state + 1] = state + 1; // //처리한 부분을 보면 N == 0일 경우 visit[1] = 0이 되어버림(방문하지 않은 것 처럼 오해함.).. 그래서 state + 1을 하고 44번째 줄에서 -1 을 함.
            move.emplace(state + 1, time + 1);
        }
        if (state < K && !visit[state * 2])
        {
            visit[state * 2] = state + 1; //
            move.emplace(state * 2, time + 1);
        }
        if (state - 1 >= 0 && !visit[state - 1])
        {
            visit[state - 1] = state + 1; //
            move.emplace(state - 1, time + 1);
        }
    }
    cout << time << "\n";
    cout << N;
    while (state != N)
    {
        ans.push(state);
        state = visit[state] - 1; // -1을 해야함.
    }
    while (!ans.empty())
    {
        cout << " " << ans.top();
        ans.pop();
    }
}

int main(void)
{
    int N, K;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N >= K)
    {
        cout << N - K << '\n';
        while (N >= K)
            cout << N-- << " ";
    }
    else
        bfs(N, K);
}