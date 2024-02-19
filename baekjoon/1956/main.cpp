#include <iostream>
#include <vector>

#define INF (long long int)2e9

using namespace std;

int main(void)
{
    long long int min_path[401][401];
    int V, E, a, b, c;
    long long int ans = INF;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            min_path[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        min_path[a][b] = c;
    }
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                //cout << "min_path[" << j  << "][" << k << "]" << min_path[j][k] << ": " << min_path[j][i] + min_path[i][k] << endl;
                min_path[i][j] = min(min_path[i][j], min_path[i][k] + min_path[k][j]);
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        ans = min(ans, min_path[i][i]);
    }
    if (ans == INF)
        cout << "-1";
    else
        cout << ans;
}