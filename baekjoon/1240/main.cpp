// LCA(Lowest Common Ancestor) = 0m/s
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > edge[1001];
int parent[1001], distan[1001], depth[1001];

void make_ancestor(int node, int dep, int dis)
{
	distan[node] = dis;
	depth[node] = dep;
	for (auto i : edge[node])
	{
		if (!parent[i.first])
		{
			parent[i.first] = node;
			make_ancestor(i.first, dep + 1, dis + i.second);
		}
	}
}

int find_parent(int node, int dep)
{
	if (dep == 0)
		return node;
	return find_parent(parent[node], dep - 1);
}

int find_ancestor(int x, int y)
{
	if (depth[x] > depth[y])
		x = find_parent(x, depth[x] - depth[y]);
	else if (depth[x] < depth[y])
		y = find_parent(y, depth[y] - depth[x]);
	while (x != y)
	{
		x = find_parent(x, 1);
		y = find_parent(y, 1);
	}
	return x;
}

int main(void)
{
	int N, M, x, y, dis, ancest;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> x >> y >> dis;
		edge[x].push_back(make_pair(y, dis));
		edge[y].push_back(make_pair(x, dis));
	}
	parent[x] = x;
	make_ancestor(x, 0, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		ancest = find_ancestor(x, y);
		dis = distan[x] + distan[y] - 2 * distan[ancest];
		cout << dis << '\n';
	}
}

// dijkstra * N = 48m/s
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// typedef struct s_compare
// {
// 	bool operator()(pair<int, int> a, pair<int, int> b)
// 	{
// 		return (a.second > b.second);
// 	}
// }  compare;

// priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
// vector<pair<int, int> > edge[1001];
// int dp[1001][1001];

// int main(void)
// {
// 	int N, M, x, y, dis;
// 	pair<int, int> ed;
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> N >> M;
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		cin >> x >> y >> dis;
// 		edge[x].push_back(make_pair(y, dis));
// 		edge[y].push_back(make_pair(x, dis));
// 	}
// 	for (int i = 1; i <= N; i++)
// 	{
// 		pq.push(make_pair(i, 0));
// 		while (!pq.empty())
// 		{
// 			ed = pq.top();
// 			//cout << i << " " << ed.first << " " << ed.second << endl;
// 			pq.pop();
// 			dp[i][ed.first] = ed.second;
// 			for (auto node : edge[ed.first])
// 			{
// 				if (!dp[i][node.first] && i != node.first)
// 				{
// 					pq.push(make_pair(node.first, node.second + ed.second));
// 				}
// 			}
// 		}
// 		while (!pq.empty())
// 			pq.pop();
// 	}
// 	for (int i = 0; i < M; i++)
// 	{
// 		cin >> x >> y;
// 		cout << dp[x][y] << '\n';
// 	}
// }


// floyd-warshall = 1000m/s
// #include <iostream>

// using namespace std;

// int main(void)
// {
// 	int N, M, dp[1001][1001], x, y, dis;
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> N >> M;
// 	for (int i = 1; i <= N; i++)
// 	{
// 		for (int j = 1; j <= N; j++)
// 		{
// 			if (i == j)
// 				dp[i][j] = 0;
// 			else
// 				dp[i][j] = 1e9;
// 		}
// 	}
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		cin >> x >> y >> dis;
// 		dp[x][y] = dis;
// 		dp[y][x] = dis;
// 	}
// 	for (int k = 1; k <= N; k++)
// 	{
// 		for (int i = 1; i <= N; i++)
// 		{
// 			for (int j = 1; j <= N; j++)
// 			{
// 				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
// 			}
// 		}
// 	}
// 	for (int i = 0; i < M; i++)
// 	{
// 		cin >> x >> y;
// 		if (x >= y)
// 			cout << dp[y][x] << '\n';
// 		else
// 			cout << dp[x][y] << '\n';
// 	}
// }
