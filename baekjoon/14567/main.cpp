#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int> > qu; // 번호, 횟수
vector<int> subject[1001];
int visit[1001];
int check[1001];

int main(void)
{
	int N, M, A, B;
	pair<int, int> sub;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		subject[A].push_back(B);
		check[B] += 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
			qu.push(make_pair(i, 0));
	}

	while(!qu.empty())
	{
		sub = qu.front();
		qu.pop();
		if (visit[sub.first])
			continue;
		visit[sub.first] = sub.second + 1;
		for (auto i : subject[sub.first])
		{
			if (check[i] > 0)
				check[i] -= 1;
			if (!visit[i] && !check[i])
				qu.push(make_pair(i, sub.second + 1));
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << visit[i] << " ";
	}
}
