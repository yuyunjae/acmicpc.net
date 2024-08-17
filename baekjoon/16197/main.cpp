#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_node
{
	int a_pos[2];
	int b_pos[2];
	int count;
} t_node;

bool map[22][22];
bool visit[22][22][22][22];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<t_node> point;

int main(void)
{
	int N, M, check, pos[2][2], index = 0;
	char temp;
	t_node node, dummy;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> temp;
			if (temp == '#')
				map[i][j] = true;
			else if (temp == 'o')
			{
				pos[index][0] = i;
				pos[index++][1] = j;
			}
		}
	}
	node.a_pos[0] = pos[0][0];
	node.a_pos[1] = pos[0][1];
	node.b_pos[0] = pos[1][0];
	node.b_pos[1] = pos[1][1];
	node.count = 0;
	point.push(node);

	while (!point.empty())
	{
		node = point.front();
		//cout << node.a_pos[0] << " " << node.a_pos[1] << " " << node.b_pos[0] << " " << node.b_pos[1] << " " << node.count  << endl;
		point.pop();
		// visit[node.a_pos[0]][node.a_pos[1]][node.b_pos[0]][node.b_pos[1]] = true;
		if (node.count >= 10)
			break ;
		dummy.count = node.count + 1;
		for (int i = 0; i < 4; i++)
		{
			check = 0;
			if (!map[node.a_pos[0] + dir[i][0]][node.a_pos[1] + dir[i][1]])
			{
				dummy.a_pos[0] = node.a_pos[0] + dir[i][0];
				dummy.a_pos[1] = node.a_pos[1] + dir[i][1];
			}
			else
			{
				dummy.a_pos[0] = node.a_pos[0];
				dummy.a_pos[1] = node.a_pos[1];
			}
			if (!map[node.b_pos[0] + dir[i][0]][node.b_pos[1] + dir[i][1]])
			{
				dummy.b_pos[0] = node.b_pos[0] + dir[i][0];
				dummy.b_pos[1] = node.b_pos[1] + dir[i][1];
			}
			else
			{
				dummy.b_pos[0] = node.b_pos[0];
				dummy.b_pos[1] = node.b_pos[1];
			}
			//cout << dummy.a_pos[0] << " " << dummy.a_pos[1] << " " << dummy.a_pos[0] << " " << dummy.a_pos[1]  << endl;
			if (dummy.a_pos[0] == dummy.b_pos[0] && dummy.a_pos[1] == dummy.b_pos[1])
				continue;
			if (dummy.a_pos[0] <= 0 || dummy.a_pos[0] > N || dummy.a_pos[1] <= 0 || dummy.a_pos[1] > M)
				check++;
			if (dummy.b_pos[0] <= 0 || dummy.b_pos[0] > N || dummy.b_pos[1] <= 0 || dummy.b_pos[1] > M)
				check++;
			if (check == 1)
			{
				cout << dummy.count;
				return (0);
			}
			else if (check == 0 && !visit[dummy.a_pos[0]][dummy.a_pos[1]][dummy.b_pos[0]][dummy.b_pos[1]])
			{
				visit[node.a_pos[0]][node.a_pos[1]][node.b_pos[0]][node.b_pos[1]] = true;
				point.push(dummy);
			}
		}
	}
	cout << -1;
}
