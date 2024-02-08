#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > ripe;
int tomato[1001][1001];
int day[1001][1001];
int moveto[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main(void)
{
    int M, N, row, col, d_r, d_c, maxi;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
            ripe.push({i, j});
        }
    }
    maxi = 0;
    while (!ripe.empty())
    {
        row = ripe.front().first;
        col = ripe.front().second;
        ripe.pop();
        for (int i = 0; i < 4; i++)
        {        
            d_r = row + moveto[i][0];
            d_c = col + moveto[i][1];
            if (d_r < 0 || d_r >= N || d_c < 0 || d_c >= M)
                continue;
            if (tomato[d_r][d_c] == 0)
            {
                tomato[d_r][d_c] = 1;
                day[d_r][d_c] = day[row][col] + 1;
                maxi = max(maxi, day[d_r][d_c]);
                ripe.push({d_r, d_c});
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tomato[i][j] == 0)
            {
                cout << "-1";
                return (0);
            }
        }
    }
    cout << maxi;
}