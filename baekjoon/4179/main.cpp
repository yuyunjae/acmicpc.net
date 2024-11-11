#include <iostream>
#include <string>
#include <queue>

using namespace std;

# define MAXI 3000

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mapi[1000][1000];

int main(void)
{
    int R, C;
    int start_x, start_y;
    string str;
    pair<pair<int, int>, int> p;
    queue<pair<pair<int, int>, int> > qu;
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> str;
        for (int j = 0; j < C; j++)
        {
            mapi[i][j] = MAXI;
            if (str[j] == 'J')
            {
                start_x = i;
                start_y = j;
            }
            else if (str[j] == 'F')
            {
                qu.emplace(make_pair(i, j), 0);
                mapi[i][j] = 0;
            }
            else if (str[j] == '#')
                mapi[i][j] = -1;
        }
    }
    // for (int i = 0; i < R; i++)
    // {
    //     for (int j = 0; j < C; j++)
    //     {
    //         cout << mapi[i][j];
    //     }
    //     cout << endl;
    // }
    if (start_x == 0 || start_y == 0 || start_x == R - 1 || start_y == C - 1)
    {
        cout << 1;
        return (0);
    }
    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = p.first.first + dx[i];
            int y = p.first.second + dy[i];

            if (x > -1 && y > -1 && x < R && y < C && mapi[x][y] == MAXI)
            {
                mapi[x][y] = p.second + 1;
                qu.emplace(make_pair(x, y), p.second + 1);
            }
        }
    }
    // for (int i = 0; i < R; i++)
    // {
    //     for (int j = 0; j < C; j++)
    //     {
    //         cout << mapi[i][j];
    //     }
    //     cout << endl;
    // }
    
    qu.emplace(make_pair(start_x, start_y), 0);
    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = p.first.first + dx[i];
            int y = p.first.second + dy[i];

            if (x > -1 && y > -1 && x < R && y < C && mapi[x][y] > p.second + 1)
            {
                mapi[x][y] = p.second + 1;
                qu.emplace(make_pair(x, y), p.second + 1);
                if (x == 0 || y == 0 || x == R - 1 || y == C - 1)
                {
                    cout << p.second + 2;
                    return (0);
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}