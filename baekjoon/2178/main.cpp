#include <iostream>
#include <queue>

using namespace std;

bool path[102][102];
queue<pair<int, int>> pos;
int visit[102][102];
int state[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs()
{
    if (pos.empty())
        return ;
    
    int y = pos.front().first;
    int x = pos.front().second;
    int block = visit[y][x];
    pos.pop();

    for (int i = 0; i < 4; i++)
    {
        if (path[y + state[i][0]][x + state[i][1]] && !visit[y + state[i][0]][x + state[i][1]])
        {
            visit[y + state[i][0]][x + state[i][1]] = block + 1;
            pos.push({y + state[i][0], x + state[i][1]});
            //cout << y + state[i][0] << " " << x + state[i][1] << " " << block + 1 << endl;
        }
    }
    bfs();
}

int main(void)
{
    int N, M;
    char str[101];

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> str;
        for (int j = 1; j <= M; j++)
        {
            path[i][j] = str[j - 1] - '0';
            //cout << path[i][j];
        }
        //cout << endl;
    }
    pos.push({1, 1});
    visit[1][1] = 1;
    bfs();
    cout << visit[N][M];
}