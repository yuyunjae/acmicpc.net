#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[1000001];

int bfs(int N)
{    
    queue<pair<int, int> > seq;
    int n, count;

    seq.emplace(1, 0);
    while (!seq.empty())
    {
        n = seq.front().first;
        count = seq.front().second;
        seq.pop();
        if (n == N)
            return (count);
        if (n + 1 <= N && !visit[n + 1])
        {
            visit[n + 1] = n;
            seq.emplace(n + 1, count + 1);
        }
        if (n * 2 <= N && !visit[n * 2])
        {
            visit[n * 2] = n;
            seq.emplace(n * 2, count + 1);
        }
        if (n * 3 <= N && !visit[n * 3])
        {
            visit[n * 3] = n;
            seq.emplace(n * 3, count + 1);
        }
    }
    return (0);
}

int main(void)
{
    int N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cout << bfs(N) << '\n' << N;
    while (visit[N])
    {
        cout << " " << visit[N];
        N = visit[N];
    }
}


/* // dp 풀이
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> dp(n+1);
	vector<int> before(n + 1);
	before[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1]+1;
		before[i] = i - 1;
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				before[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				before[i] = i / 2;
			}
		}
		
	}
	cout << dp[n]<<'\n';
	if(n!=0)
		cout << n << ' ';
	while (n != 1) {
		n = before[n];
		cout << n << ' ';
	}
	return 0;
}

*/