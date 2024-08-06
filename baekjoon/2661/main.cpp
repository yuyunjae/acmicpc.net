#include <iostream>
#include <vector>
#include <string>

using namespace std;

// string str;
int N;
int	arr[80];

bool check_okay(int i)
{
	int index = i;
	while (index--)
	{
		if (arr[index] == arr[i])
		{
			int ind = index - 1;
			int j = i - 1;
			while (index < j && ind >= 0 && arr[ind] == arr[j])
			{
				ind--;
				j--;
			}
			if (index >= j)
				return false;
		}
	}
	return true;
}

bool dfs(int i)
{
	if (i == N)
	{
		for(int j = 0; j < N; j++)
			cout << arr[j];
		return true;
	}
	for (int j = 1; j <= 3; j++)
	{
		arr[i] = j;
		if (check_okay(i))
		{
			if (dfs(i + 1))
				return true;
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= 3; i++)
	{
		arr[0] = i;
		if (dfs(1))
			break ;
	}
}
