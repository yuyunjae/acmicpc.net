#include <iostream>
#include <algorithm>

using namespace std;

int	country[6][3];
int match[15][2];

int dfs(int i)
{
	if (i == 15)
	{
		for (int j = 0; j < 6; j ++)
		{
			if (country[j][0] || country[j][1] || country[j][2])
				return 0;
		}
		return 1;
	}

	for(int j = 0; j < 3; j++)
	{
		if (country[match[i][0]][j] && country[match[i][1]][2 - j])
		{
			country[match[i][0]][j]--;
			country[match[i][1]][2 - j]--;
			if (dfs(i + 1))
				return 1;
			country[match[i][0]][j]++;
			country[match[i][1]][2 - j]++;
		}
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	for(int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			match[count][0] = i;
			match[count++][1] = j;
		}
	}

	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
			cin >> country[j][0] >> country[j][1] >> country[j][2];
		cout << dfs(0) << " ";
	}
}
