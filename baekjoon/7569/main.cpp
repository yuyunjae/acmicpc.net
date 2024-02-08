#include <iostream>
#include <queue>

using namespace std;

queue<pair<pair<int, int>, pair<int, int> > > ripe; // x, y, z, day
int tomato[101][101][101];
int moveto[6][3] = {{0, 0, -1}, {0, 0, 1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

int main(void)
{
    int M, N, H, x, y, z, d_x, d_y, d_z, day, maxi;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N >> H;
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> tomato[h][i][j];
                if (tomato[h][i][j] == 1)
                ripe.push({{h, i},{j, 0}}); // z, y, x, day
            }
        }
    }
    maxi = 0;
    while (!ripe.empty())
    {
        z = ripe.front().first.first;
        y = ripe.front().first.second;
        x = ripe.front().second.first;
        day = ripe.front().second.second;
        maxi = max(maxi, day);
        ripe.pop();
        for (int i = 0; i < 6; i++)
        {        
            d_z = z + moveto[i][0];
            d_y = y + moveto[i][1];
            d_x = x + moveto[i][2];
            if (d_z >= 0 && d_y >= 0 && d_x >= 0 && d_z < H && d_y < N && d_x < M)
            {
                if (tomato[d_z][d_y][d_x] == 0)
                {
                    tomato[d_z][d_y][d_x] = 1;
                    ripe.push({{d_z, d_y}, {d_x, day + 1}});
                }
            }
        }
    }
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (tomato[h][i][j] == 0)
                {
                    cout << "-1";
                    return (0);
                }
            }
        }
    }
    cout << maxi;
}