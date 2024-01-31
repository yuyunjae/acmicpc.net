#include <iostream>
#define INT_MAX 2147483647

using namespace std;

int dp[500][500];
int matrix[500][2];

int main(void)
{
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1];
    }
    for (int d = 1; d < N; d++)
    {
        for (int x = 0; x < N - d; x++)
        {
            dp[x][x + d] = INT_MAX;
            for (int mid = x; mid < x + d; mid++)
            {
                dp[x][x + d] = min(dp[x][x + d], dp[x][mid] + dp[mid + 1][x + d] + matrix[x][0] * matrix[mid][1] * matrix[x + d][1]);
            }
        }
    }
    cout << dp[0][N - 1];
}
