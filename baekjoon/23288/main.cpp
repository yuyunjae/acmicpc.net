#include <iostream>
#include <queue>

using namespace std;

int map[22][22];
bool visit[22][22];
int dice[6] = {2, 4, 1, 3, 5, 6};
/*
	2
4	1	3
	5
	6
// 4가 주사위 위쪽, 1이 주사위 오른쪽
*/
int point[2] = {1, 1};
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int move_way;
int N, M, K;
unsigned long long int ans;
queue<pair<int, int> > qu;

void	roll_dice(int way)
{
	int temp;

	switch (way)
	{
		case 0: // roll right
			temp = dice[3];
			dice[3] = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = temp;
			break ;
		case 1: // down
			temp = dice[5];
			dice[5] = dice[4];
			dice[4] = dice[2];
			dice[2] = dice[0];
			dice[0] = temp;
			break ;
		case 2: // left
			temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[5];
			dice[5] = temp;
			break ;
		case 3: // up
			temp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[4];
			dice[4] = dice[5];
			dice[5] = temp;
			break ;
	}
}

void	clear_visit()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			visit[i][j] = 0;
	}
}

int main(void)
{
	int val;
	pair<int, int> state;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < K; i++)
	{
		point[0] += movement[move_way][0];
		point[1] += movement[move_way][1];
		if (map[point[0]][point[1]] == 0)
		{
			point[0] -= 2 * movement[move_way][0];
			point[1] -= 2 * movement[move_way][1];
			move_way = (move_way + 2) % 4;
		}
		roll_dice(move_way);
		val = map[point[0]][point[1]];
		qu.push(make_pair(point[0], point[1]));
		while (!qu.empty())
		{
			state = qu.front();
			qu.pop();
			if (visit[state.first][state.second])
				continue;
			visit[state.first][state.second] = true;
			ans += val;
			for (int j = 0; j < 4; j++)
			{
				if (!visit[state.first + movement[j][0]][state.second + movement[j][1]] && map[state.first + movement[j][0]][state.second + movement[j][1]] == val)
					qu.push(make_pair(state.first + movement[j][0], state.second + movement[j][1]));
			}
		}
		clear_visit();
		if (dice[5] > val)
			move_way  = (move_way + 1) % 4;
		if (dice[5] < val)
			move_way  = (move_way + 3) % 4;

		// cout << point[0] << "  " << point[1] <<  " " << move_way << endl;
		// cout << "	" << dice[0] << endl;
		// cout << dice[1] << "	" << dice[2] << "	" << dice[3] << endl;
		// cout << "	" << dice[4] << endl;
		// cout << "	" << dice[5] << endl;
	}
	cout << ans;
}
