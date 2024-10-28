#include <iostream>

using namespace std;

int charge[20];
int pay;
int dp[10001];

int main(void)
{
    int T, N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> charge[j];
        cin >> pay;

        dp[0] = 1;
        for (int j = 0; j < N; j++)
        {
            for (int k = charge[j]; k <= pay; k++)
            {
                dp[k] += dp[k - charge[j]];
            }
        }
        cout << dp[pay] << '\n';
        fill(dp, dp + pay + 1, 0);
    }
}