// dfs와 bfs의 차이를 명확하게 구분할 수 있어야 할듯. 이번의 경우, cycle도 없고 bfs의 경우, max_val을 계속 들고다녀야하므로 번거로움.. 따라서 dfs가 더 유리하다.

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > node[100001];
bool visit[100001];
int S, E, ans;

void dfs(int start, int max_val)
{
	visit[start] = true;
	for (auto i : node[start])
	{
		if (!visit[i.first])
		{
			if (i.first == E)
			{
				cout << ans + i.second - max(max_val, i.second);
				return ;
			}
			ans += i.second;
			dfs(i.first, max(max_val, i.second));
			ans -= i.second;
		}
	}
}

int main(void)
{
	int N, a, b, val;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S >> E;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> val;
		node[a].push_back(make_pair(b, val));
		node[b].push_back(make_pair(a, val));
	}
	if (S == E)
		cout << "0";
	else
		dfs(S, 0);
}
