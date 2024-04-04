#include <iostream>

using namespace std;

#define MODD 1000000000
#define MOD int(1e9)
#define MM 1000
#define MD int(10e2)

int dp[201][201];

int main(void)
{
    int N, K;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i <= 200; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int p = 0; p <= j; p++)
            {
                dp[i][j] += dp[i - 1][p];
                dp[i][j] %= 1000000000;
            }
        }
    }
    cout << dp[K][N];
    // ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ... 10e9 는 10 x 10^9 이므로 10^10인데.. 10^9로 생각해서 해맸던 문제.. 수학공부를 다시하자.
    // if (1000000000 == MODD)
    //     cout << "AA";
    // if (1000000000 == MOD)
    //     cout << "BB";
    // if (1000000000 == int(MOD))
    //     cout << "CC";
    // if (1000 == MM)
    //     cout << "DD";
    // if (1000 == MD)
    //     cout << "EE";
    // if (1000 == int(MD))
    //     cout << "FF";
}