// 이거 dp(start, end)가 start에서 end까지의 최대값이 아니라, start, end가 남았을 때의 최댓값으로도 한 번 풀어보기
#include <iostream>
#include <algorithm>

using namespace std;

int inp[1001];
int arr[1001][1001];

int dp(int start, int end, int turn)
{
	if (start > end)
		return (0);
	if (arr[start][end])
		return (arr[start][end]);
	if (turn % 2 == 0)
		arr[start][end] = max(dp(start + 1, end, turn + 1) + inp[start], dp(start, end - 1, turn + 1) + inp[end]);
	else
		arr[start][end] = min(dp(start + 1, end, turn + 1), dp(start, end - 1, turn + 1));
	return (arr[start][end]);
}

int main(void)
{
	int T, N, ans;
	bool turn = true;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> inp[j];
		cout << dp(0, N - 1, 0) << '\n';
		fill(&arr[0][0], &(arr[N - 1][N]), 0);
	}
}
