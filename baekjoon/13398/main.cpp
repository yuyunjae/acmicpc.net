#include <iostream>
#include <algorithm>

using namespace std;

int dp[100002][2];
int seri[100002];

int main(void)
{
	int n, temp;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seri[i];
	dp[0][0] = seri[0];
	dp[0][1] = seri[0];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + seri[i], seri[i]);
		dp[i][1] = max(dp[i - 1][1] + seri[i], seri[i]);
		if (seri[i] < 0)
			dp[i][1] = max(dp[i][1], dp[i - 1][0]);
	}
	cout << *max_element(dp[0], dp[0] + 2 * n);
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int dp[100002][2];
// int seri[100002];

// int main(void)
// {
// 	int n, j = 0, temp;

// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> n >> temp;

// 	seri[j] = temp;

// 	for (int i = 1; i < n; i++)
// 	{
// 		cin >> temp;
// 		if (temp < 0)
// 			seri[++j] = temp;
// 		else
// 		{
// 			if (seri[j] >= 0)
// 				seri[j] += temp;
// 			else
// 				seri[++j] = temp;
// 		}
// 	}
// 	// for (int i = 0; i <= j; i++)
// 	// 	cout << seri[i] << endl;
// 	dp[0][0] = seri[0];
// 	dp[0][1] = seri[0];

// 	for (int i = 1; i <= j; i++)
// 	{
// 		dp[i][0] = max(dp[i - 1][0] + seri[i], seri[i]);
// 		dp[i][1] = max(dp[i  - 1][1] + seri[i], seri[i]);
// 		if (seri[i] < 0)
// 			dp[i][1] = max(dp[i][1], dp[i - 1][0]);
// 		//cout << i <<  " " << dp[i][0] << " " << dp[i][1] << endl;
// 	}
// 	cout << *max_element(dp[0], dp[0] + 2 * j + 2);
// }
