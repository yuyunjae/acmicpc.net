#include <iostream>

using namespace std;

int main(void)
{
	unsigned int M, N, x, y;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	if (N >= M)
	{
		cout << 2 * M - 2 << '\n';
		if (N == M)
		{
			cout << (N + 2)/2 << " " << (N + 1)/2;
		}
		else if (M % 2) // 홀수
		{
			cout << (M + 2) / 2 << " " << N - M / 2;
		}
		else // 짝수
		{
			cout << (M + 3) / 2 << " " << M / 2;
		}
	}
	else
	{
		cout << 2 * N - 1 << '\n';
		if (N % 2) // 홀수
		{
			cout << M - N / 2 << " " << (N + 2) / 2;
		}
		else // 짝수
		{
			cout << (N + 3) / 2 << " " << N / 2;
		}
	}
}
