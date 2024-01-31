#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];

int main(void)
{
    int n, k, coin;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        if (coin > k)
            continue;
        dp[coin] += 1;
        for (int j = coin; j <= k; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[k];
}