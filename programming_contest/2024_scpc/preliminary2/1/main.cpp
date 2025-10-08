// 200/200   
/* 
dp를 조금 더 공부하자. 공간 크기도 중요하지만, 이전 값을 누적적으로 사용하는 것이 훨씬 좋다.
main1.cpp같은 경우, 너무 비효율적인 dp를 사용해서 빨라보이지만 매우 느린 알고리즘이 만들어져버렸다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXI 1e17

unsigned long long int Answer, dp[300001][3];

int main(int argc, char** argv)
{
	int T, test_case, N, S, E, temp;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> N >> S >> E;
        
        for (int i = 1; i <= N; i++)
        {
            cin >> temp;
            if (temp) // 1이 올 때
            {
                dp[i][0] = dp[i - 1][0] + E;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
                dp[i][2] = min(dp[i - 1][1] + E, dp[i - 1][2] + E);
            }
            else /// 0이 올 때
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = min(dp[i - 1][1] + S, dp[i - 1][0] + S);
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            }
        }
        Answer = min(dp[N][0], dp[N][1]);
        Answer = min(Answer, dp[N][2]);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}