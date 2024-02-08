#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > pos;
int visit[301][301];
int dest[2];
int chess;
int moveto[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

void    bfs()
{
    if (pos.empty())
        return ;

    int val_x = pos.front().first, val_y = pos.front().second;
    int state_x, state_y;
    pos.pop();
    for (int i = 0; i < 8; i++)
    {
        state_x = val_x + moveto[i][0];
        state_y = val_y + moveto[i][1];
        if (!visit[state_x][state_y])
        {
            if (state_x == dest[0] && state_y == dest[1])
            {
                visit[state_x][state_y] = visit[val_x][val_y] + 1;
                return ;
            }
            else if (state_x >= 0 && state_x < chess && state_y >= 0 && state_y < chess)
            {
                visit[state_x][state_y] = visit[val_x][val_y] + 1;
                pos.push({state_x, state_y});
            }
        }
    }
    bfs();
}

int main(void)
{
    int test, x, y;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> chess >> x >> y >> dest[0] >> dest[1];
        if (x == dest[0] && y == dest[1])
        {
            cout << "0\n";
            continue;
        }
        pos.push({x, y});
        bfs();
        cout << visit[dest[0]][dest[1]] << '\n';
        for (int i = 0; i < chess; i++)
        {
            for (int j = 0; j < chess; j++)
            {
                visit[i][j] = 0;
            }
        }
        while (!pos.empty())
            pos.pop();
    }
}