// sol 28m/s O(n^3)
#include <iostream>
#include <queue>
#include <vector>

#define MAXI (long long int)(1e10 + 1)

using namespace std;

long long int path[101][101];
int before[101][101];
vector<int> ans_way;

void    find_way(int start, int end)
{
    if (before[start][end])
    {
        find_way(start, before[start][end]);
        ans_way.pop_back();
        find_way(before[start][end], end);
    }
    else 
    {
        ans_way.push_back(start);
        ans_way.push_back(end);
    }
}

int main(void)
{
    int n, m, start, end, cost;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = MAXI;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end >> cost;
        path[start][end] = min(path[start][end], (long long int)cost);
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (path[i][j] > path[i][k] + path[k][j])
                {
                    path[i][j] = path[i][k] + path[k][j];
                    before[i][j] = k;
                }
            }   
        }   
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (path[i][j] == MAXI)
                cout << "0 ";
            else
                cout << path[i][j] << " ";
        }
        cout << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (path[i][j] == MAXI || path[i][j] == 0)
                cout << "0\n";
            else
            {
                ans_way.clear();
                find_way(i, j);
                cout << ans_way.size();
                for (auto val : ans_way)
                    cout << " " << val;
                cout << '\n';
            }
        }
    }
}

/* 
// 3차원 백터 풀이법.. 당연히 시간초과를 예상했으나, 32m/s 통과.. O(n^3 * (way[i][k].size() + way[k][j].size())) 라고 생각해서 최악의 경우 O(n^4)까지 생각했으나, 아니였다보다.
// 하지만 더 효율적인 풀이가 있으므로 해당 풀이를 정석으로 생각하겠다.
#include <iostream>
#include <queue>
#include <vector>

#define MAXI (long long int)(1e10 + 1)

using namespace std;

long long int path[101][101];

int main(void)
{
    int n, m, start, end, cost;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<vector<long long int> > > way(n + 1, vector<vector<long long int> >(n + 1));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                path[i][j] = 0;
                way[i][j].push_back(i);
            }
            else
            {
                path[i][j] = MAXI;
                way[i][j].push_back(i);
                way[i][j].push_back(j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end >> cost;
        path[start][end] = min(path[start][end], (long long int)cost);
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (path[i][j] > path[i][k] + path[k][j])
                {
                    path[i][j] = path[i][k] + path[k][j];
                    way[i][j].clear();
                    for (int index = 0; index < way[i][k].size(); index++)
                        way[i][j].push_back(way[i][k][index]);
                    for (int index = 1; index < way[k][j].size(); index++)
                        way[i][j].push_back(way[k][j][index]);
                }
            }   
        }   
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (path[i][j] == MAXI)
                cout << "0 ";
            else
                cout << path[i][j] << " ";
        }
        cout << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (path[i][j] == MAXI || path[i][j] == 0)
                cout << "0\n";
            else
            {
                cout << way[i][j].size();
                for (auto val : way[i][j])
                    cout << " " << val;
                cout << '\n';
            }
        }
    }
}
*/