#include <iostream>

using namespace std;

int app[101][2];
int dp[101][10001];

int binary_search(int N, int M, int sum)
{
    int left = 0, right = sum, mid;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (dp[N][mid] >= M)
            right = mid;
        else
            left = mid + 1;
    }
    return (right);
}

int main(void)
{
    int N, M, sum = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> app[i][0];
    for (int i = 0; i < N; i++)
    {
        cin >> app[i][1];
        sum += app[i][1];
    }
    for (int i = app[0][1]; i <= sum; i++)
        dp[0][i] = app[0][0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j - app[i][1] < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - app[i][1]] + app[i][0]);
        }
    }
    cout << binary_search(N - 1, M, sum);
}
