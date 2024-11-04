#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int mapi[8][8];
int curr_map[8][8];
int N, M, answer;
int dir[2][4] = {{0, 0, -1, 1}, {1, -1, 0, 0}};

vector<pair<int, int> > virus;
queue<pair<int, int> > qu;

void max_ans(void)
{
    int check_ans = 0;
    for  (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!curr_map[i][j])
                check_ans += 1;
            curr_map[i][j] = mapi[i][j];
        }
    }
    answer = max(answer, check_ans);
}

void bfs()
{
    pair <int, int> p;
    while (!qu.empty()) qu.pop();
    for (auto i : virus)
        qu.push(i);
    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = p.first + dir[0][i];
            int b = p.second + dir[1][i];
            if (a < 0 || b < 0 || a >= N || b >= M)
                continue;
            if (curr_map[a][b] == 0)
            {
                curr_map[a][b] = 2;
                qu.emplace(a, b);
            }
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mapi[i][j];
            curr_map[i][j] = mapi[i][j];
            if (mapi[i][j] == 2)
                virus.emplace_back(i, j);
        }
    }
    for (int i = 0; i < N * M; i++)
    {
        if (curr_map[i / M][i % M] != 0)
            continue;
        for (int j = i + 1; j < N * M; j++)
        {
            if (curr_map[j / M][j % M] != 0)
                continue;
            for (int k = j + 1; k < N * M; k++)
            {
                if (curr_map[k / M][k % M] != 0)
                    continue;
                curr_map[i / M][i % M] = 1;
                curr_map[j / M][j % M] = 1;
                curr_map[k / M][k % M] = 1;
                bfs();
                max_ans();
            }
        }
    }
    cout << answer;
}