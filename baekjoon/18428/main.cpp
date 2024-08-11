#include <iostream>
#include <vector>

using namespace std;

char map[7][7];
int N;
vector<pair<int, int> > student;
vector<pair<int, int> > teacher;

bool check_okay()
{
	for (auto stu : student)
	{
		for (int i = stu.second + 1; i < N; i++)
		{
			if (map[stu.first][i] == 'O')
				break ;
			if (map[stu.first][i] == 'T')
				return false;
		}
		for (int i = stu.second - 1; i >= 0; i--)
		{
			if (map[stu.first][i] == 'O')
				break ;
			if (map[stu.first][i] == 'T')
				return false;
		}
		for (int i = stu.first + 1; i < N; i++)
		{
			if (map[i][stu.second] == 'O')
				break ;
			if (map[i][stu.second] == 'T')
				return false;
		}
		for (int i = stu.first; i >= 0; i--)
		{
			if (map[i][stu.second] == 'O')
				break ;
			if (map[i][stu.second] == 'T')
				return false;
		}
	}
	return true;
}

bool dfs(int max, int index)
{
	if (max == 3)
	{
		return check_okay();
	}
	for (int i = index; i < N * N; i++)
	{
		if (map[i / N][i % N] == 'X')
		{
			map[i / N][i % N] = 'O';
			if (dfs(max + 1, i + 1))
				return true;
			map[i / N][i % N] = 'X';
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
				student.push_back(make_pair(i, j));
			else if (map[i][j] == 'T')
				teacher.push_back(make_pair(i, j));
		}
	}
	if (check_okay() || dfs(0, 0))
		cout << "YES";
	else
		cout << "NO";
}
