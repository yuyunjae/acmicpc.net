#include <iostream>
#include <vector>
#include <tuple>

#define INF (long long int)2e10

using namespace std;

long long int min_path[101][101];
//vector<tuple<int, int, int> > edge;

int main(void) //플로이드 워셜(floyd-warshall)
{
    int n, m;
    long long int a, b, c;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                min_path[i][j] = 0;
            else
                min_path[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        //edge.emplace_back(a, b, c);
        min_path[a][b] = min(min_path[a][b], c);
    }
    for (int i = 1; i <= n; i++) //경유점
    {
        for (int j = 1; j <= n; j++) // 출발점
        {
            for (int k = 1; k <= n; k++) //도착점
            {
                //cout << "min_path[" << j  << "][" << k << "]" << min_path[j][k] << ": " << min_path[j][i] + min_path[i][k] << endl;
                min_path[j][k] = min(min_path[j][k], min_path[j][i] + min_path[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (min_path[i][j] == INF)
                cout << "0 ";
            else
                cout << min_path[i][j] << " ";
        }
        cout << "\n";
    }
}