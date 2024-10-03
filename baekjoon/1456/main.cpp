/* if
{
	//
}
42하면서 이런 꼴로 썼는데, 오히려 가독성이 떨어지는 것 같기도 하다..
if {
	//
}
이게 더 좋을 수도..
*/
#include <iostream>

using namespace std;

bool visit[10000001];

int main(void)
{
	unsigned long long int N, M, ans = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	visit[2] = true;
	for (unsigned long long int j = 4; j <= M; j = j << 1)
	{
		if (j >= N)
			ans++;
	}

	//cout << ans << " ";
	for (unsigned long long int i = 3; i * i <= M; i = i + 2)
	{
		if (!visit[i])
		{
			for (unsigned long long int j = i; j * j <= M; j += 2 * i)
				visit[j] = true;

			for (unsigned long long int j = i * i; j <= M; j *= i)
			{
				if (j >= N)
					ans++;
				if (M / i < j)
					break ;
			}
		}
	}
	cout << ans;
}
