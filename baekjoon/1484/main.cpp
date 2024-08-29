#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<long long> se;

int main(void)
{
	long long G;
	bool check = false;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> G;
	for (long long i = 1; i <= 50000; i++)
		se.insert(i * i);
	for (long long i = 1; i <= 50000; i++)
	{
		if (se.find(G + i * i) != se.end())
		{
			cout << int(sqrt(G + i * i)) << '\n';
			check = true;
		}
	}
	if (!check)
		cout << -1;
}
