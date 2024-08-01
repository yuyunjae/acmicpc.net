#include <iostream>

using namespace std;

bool visit[10000001];

int main(void)
{
	unsigned long long int N, M, ans = 0, before;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	visit[2] = true;
	before = 4;
	for (unsigned long long int j = 4; j <= M; j = j << 1)
	{
		if (before > j)
			break ;
		if (j >= N)
			ans++;
		before = j;
	}
	// cout << ans << endl;
	for (unsigned long long int i = 3; i * i <= M; i = i + 2)
	{
		if (!visit[i])
		{
			//cout << i << " ";
			for (unsigned long long int j = i; j * j <= M; j += 2 * i)
				visit[j] = true;
			before = i;
			for (unsigned long long int j = i * i; j <= M; j *= i)
			{
				if (100000000000000 / before < i)
					break ;
				if (j >= N)
					ans++;
				before = j;
			}
		}
	}
	cout << ans;
}
