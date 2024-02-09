#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

queue<tuple<int, int, bool> > path; // y, x, wall_break
int mapp[1001][1001];
int visit[1001][1001][2];
int moveto[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(void)
{
    int N, M, y, x, d_y, d_x, maxi = 0;
    bool w_b;
    string str;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        for (int j = 1; j <= M; j++)
        {
            mapp[i][j] = str[j - 1] - '0';
        }
    }
    if (M == 1 && N == 1)
    {
        cout << "1";
        return (0);
    }
    path.emplace(1, 1, false);
    visit[1][1][0] = 1;
    visit[1][1][1] = 1;
    while (!path.empty())
    {
        tie(y, x, w_b) = path.front();

        path.pop();
        for (int i = 0; i < 4; i++)
        {
            d_y = y + moveto[i][0];
            d_x = x + moveto[i][1];
            if (d_y > 0 && d_y <= N && d_x > 0 && d_x <= M)
            {
                //cout << d_y << " " << d_x << " " << w_b << " " << "check\n" << endl;
                if (d_y == N && d_x == M)
                {
                    cout << visit[y][x][w_b] + 1;
                    return (0);
                }
                if (!w_b) // 부숨x
                {
                    if (!visit[d_y][d_x][0] && !mapp[d_y][d_x]) // 부숨x로 방문x && 벽이 아님.
                    {                    
                        visit[d_y][d_x][0] = visit[y][x][0] + 1;
                        //visit[d_y][d_x][1] = visit[y][x][0] + 1;
                        path.emplace(d_y, d_x, false);
                        //cout << visit[d_y][d_x][0] << ": " << d_y << " " << d_x << " " << "no\n";
                    }
                    if (!visit[d_y][d_x][1] && mapp[d_y][d_x]) // 부숨 0로 방문x && 벽임.
                    {
                        visit[d_y][d_x][1] = visit[y][x][0] + 1;
                        path.emplace(d_y, d_x, true);
                        //cout << visit[d_y][d_x][1] << ": " << d_y << " " << d_x << " " << "break_wall\n";
                    }
                }
                else if (!visit[d_y][d_x][1] && !mapp[d_y][d_x])
                {
                    visit[d_y][d_x][1] = visit[y][x][1] + 1;
                    path.emplace(d_y, d_x, true);   
                    //cout << visit[d_y][d_x][1] << ": " << d_y << " " << d_x << " " << "break_wall\n";
                }
            }
        }
        //cout << endl << get<0>(path.front()) << get<1>(path.front()) << get<2>(path.front()) << endl;
    }
    cout << "-1";
}
