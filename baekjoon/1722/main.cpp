#include <iostream>

using namespace std;

unsigned long long int per(int n, unsigned long long int ans)
{
	if (n <= 1)
		return ans;
	return per(n - 1, ans * n);
}

int main(void)
{
	int permutation[20];
	bool visit[21] = {0, };
	int N, opt, count, down, i;
	unsigned long long int ans = 1, per_num, val;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> opt;

	if (opt == 1)
	{
		cin >> val;
		val = val - 1;
		i = 0;
		for (int k = N; k > 0; k--)
		{
			per_num = per(k - 1, 1);
			count = 0;
			down = val / per_num;
			for (int j = 1; j <= N; j++)
			{
				if (!visit[j])
				{
					count++;
					if (count == down + 1)
					{
						permutation[i++] = j;
						visit[j] = true;
						val -= down * per_num;
						break ;
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
			cout << permutation[i] << " ";
	}
	else if(opt == 2)
	{
		for (int i = 0; i < N; i++)
			cin >> permutation[i];
		for (int i = 0; i < N; i++)
		{
			count = 0;
			down = 0;
			visit[permutation[i]] = true;
			for (int j = 1; j <= N; j++)
			{
				if (!visit[j])
				{
					if (j < permutation[i])
						down++;
					count++;
				}
			}
			ans += per(count, 1) * down;
		}
		cout << ans;
	}
}
