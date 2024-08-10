#include <iostream>

using namespace std;

unsigned long long int f[1000001];
unsigned long long int g[1000001];

int main(void)
{
	int T, N;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	f[1] = 1;
	for (int i = 2; i < 1000001; i++)
	{
		f[i] += 1;
		for(unsigned long long int j = i; j < 1000001; j = j + i)
			f[j] += i;
	}
	for (int i = 1; i < 1000001; i++)
		g[i] =  g[i - 1] + f[i];

	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> N;
		cout << g[N] << "\n";
	}
}
