#include <iostream>

#define INT_MAX 2147483647

using namespace std;

int sum[501];
int dp[501][501];
// 전역변수 배열 -> 자동 0으로 초기화

int main(void)
{
    int T, K, chapter;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 1; i <= T; i++)
    {   
        cin >> K;
        for (int j = 1; j <= K; j++)
        {
            cin >> chapter;
            sum[j] = sum[j - 1] + chapter;
            //cout << "sum " << j << ": " << sum[j] << '\n';
        }

        for (int distance = 1; distance <= K; distance++)
        {
            for (int start = 1; start <= K - distance; start++)
            {
                int end = start + distance;
                dp[start][end] = INT_MAX;
                for (int mid = start; mid < end; mid++)
                {
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
                    //cout << "dp[" << start << "][" << end << "]= " << dp[start][end] << '\n';
                }
            }
        }
        cout << dp[1][K] << '\n';
    }
}