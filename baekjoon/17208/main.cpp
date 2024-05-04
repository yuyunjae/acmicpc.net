/*
#include <iostream>
#include <vector>

using namespace std;

int dp[101][301][301];
vector<pair<int, int> > order;

int main(void)
{
    int N, M, K, x, y;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        if (x <= M && y <= K)
            order.emplace_back(x, y);
    }
    for (int i = 0; i < order.size(); i++)
    {
        x = order[i].first;
        y = order[i].second;
        for (int j = 0; j <= M; j++)
        {
            for (int h = 0; h <= K; h++)
            {
                if (j < x || h < y)
                    dp[i + 1][j][h] = dp[i][j][h];
                else
                    dp[i + 1][j][h] = max(dp[i][j][h], dp[i][j-x][h-y] + 1);
                //cout << i + 1 << " " << j << " " << h << " " << dp[i + 1][j][h] << '\n';
            }
        }
    }
    cout << dp[order.size()][M][K];
}
*/

#include <iostream>
#include <vector>

using namespace std;

int dp[301][301];

int main(void)
{
    int N, M, K, x, y, ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        for (int j = M; j >= x; j--)
        {
            for (int h = K; h >= y; h--)
            {
                dp[j][h] = max(dp[j][h], dp[j-x][h-y] + 1);
            }
        }
    }
    cout << dp[M][K];
}