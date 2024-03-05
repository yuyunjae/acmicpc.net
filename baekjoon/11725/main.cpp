// sol 48m/s
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> node[100001];
queue<int> q;
int ans[100001];

void bfs(int N)
{
    int parent;

    q.push(1);
    ans[1] = -1;
    while (!q.empty())
    {
        parent = q.front();
        q.pop();

        for (auto i : node[parent])
        {
            if (ans[i])
                continue;
            q.push(i);
            ans[i] = parent;
        }
    }
    for (int i = 2; i <= N; i++)
        cout << ans[i] << '\n';
}

int main(void)
{
    int N, a, b;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    bfs(N);
}