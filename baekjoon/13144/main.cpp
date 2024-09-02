#include <iostream>

using namespace std;

int main(void)
{
	int N, arr[100000], dp[100001] = {0, }, index = 0;
	unsigned long long int ans = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[arr[i]] += 1;
		while (dp[arr[i]] >= 2)
		{
			ans += i - index;
			// cout << i << ":" << index << ":" << ans << endl;
			dp[arr[index++]] -= 1;
		}
	}
	while (index < N)
	{
		ans += N - index++;
		// cout << N << ";" << index << ":" << ans << endl;
	}
	cout << ans;
}
