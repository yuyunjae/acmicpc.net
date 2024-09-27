#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct s_pos
{
	int x;
	int y;
	int distance;
} t_pos;

struct compare
{
	bool operator()(t_pos &a, t_pos &b)
	{
		if (a.distance == b.distance)
			if (a.y == b.y)
				return (a.x > b.x);
			else
				return (a.y > b.y);
		else
			return (a.distance > b.distance);
	}
};

priority_queue<t_pos, vector<t_pos>, compare> p_q;
queue<t_pos> qu;
int N;
int map[20][20];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0 , 1};

// void print_map(int y, int x, int time_all, int fish_size, int eat_count)
// {
// 	cout << "case" << ":" << time_all << " " << fish_size << " " << eat_count << endl;
// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < N; j++)
// 		{
// 			if (i == y && j == x)
// 				cout << "9 ";
// 			else
// 				cout << map[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }

int main(void)
{
	t_pos pos, temp;
	bool check = false;
	bool visit[20][20] = {0, };
	int fish_size = 2, eat_count = 0, total_time = 0, loop_max;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				pos.x = j;
				pos.y = i;
				pos.distance = 0;
				map[i][j] = 0;
			}
		}
	}
	while (1)
	{
		check = false;
		loop_max = 2147483647;
		qu.push(pos);
		visit[pos.y][pos.x] = true;
		while (!qu.empty())
		{
			pos = qu.front();
			qu.pop();
			temp.distance = pos.distance + 1;
			if (temp.distance > loop_max)
			{
				pos = p_q.top();
				total_time += pos.distance;
				// cout << pos.distance << endl;
				pos.distance = 0;
				map[pos.y][pos.x] = 0;
				eat_count++;
				// cout << pos.y << " " << pos.x << " " << total_time << " " << fish_size <<  " " << eat_count << endl;
				while (!qu.empty())
					qu.pop();
				while (!p_q.empty())
					p_q.pop();
				if (eat_count == fish_size)
				{
					eat_count = 0;
					fish_size++;
				}
				// print_map(pos.y, pos.x, total_time, fish_size, eat_count);
				check = true;
				break ;
			}
			for (int i = 0; i < 4; i++)
			{
				temp.x = pos.x + dx[i];
				temp.y = pos.y + dy[i];
				if (temp.x >= 0 && temp.y >= 0 && temp.x < N && temp.y < N && !visit[temp.y][temp.x] && fish_size >= map[temp.y][temp.x])
				{
					visit[temp.y][temp.x] = true;
					// cout << temp.y << " " << temp.x << " " << total_time << " " << endl;
					qu.push(temp);
					if (fish_size > map[temp.y][temp.x] && map[temp.y][temp.x])
					{
						p_q.push(temp);
						loop_max = temp.distance;
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = false;
			}
		}
		if (!check)
			break ;
	}
	cout << total_time;
}
