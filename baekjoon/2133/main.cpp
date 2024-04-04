#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int dp[31];

int main(void)
{
    int N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    if (N % 2)
    {
        cout << 0;
        return (0);
    }
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= 30; i+=2)
    {
        dp[i] = 3 * dp[i - 2] + 2;
        for (int j = i - 2; j >= 4; j-=2)
        {
            dp[i] += dp[j - 2] * 2;
        }
    }
    cout << dp[N];
}