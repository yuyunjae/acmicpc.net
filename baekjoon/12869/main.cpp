#include <iostream>
#include <algorithm>

using namespace std;

int dp[61][61][61];

int find_hit_count(int a, int b, int c) // a >= b >= c
{
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    if (a == 0 && b == 0 && c == 0)
        return (0);
    if (dp[a][b][c])
        return (dp[a][b][c]);
    if (c == 0 && b == 0)
    {
        dp[a][b][c] = (a % 9 == 0) ? (a / 9) : (a / 9 + 1);
        return (dp[a][b][c]);
    }
    dp[a][b][c] = min(find_hit_count(a - 9, b - 3, c - 1), find_hit_count(a - 9, b - 1, c - 3)) + 1;
    return (dp[a][b][c]);
}

int main(void)
{
    int N, scv[3] = {0, };

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> scv[i];
    sort(scv, scv + 3, greater<int>());
    cout << find_hit_count(scv[0], scv[1], scv[2]);
}

/* bfs를 이용한 다른 분의 코드인데, 이렇게 하는 것이 공간도 조금 더 아끼고 효율적인 것 같다.
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct a {
	short arr[3];
	int n;
};

int main() {
	queue<a> q;
	a tmp;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp1;
		scanf("%d", &tmp1);
		tmp.arr[i] = tmp1;
	}
	tmp.n = 0;
	sort(tmp.arr, tmp.arr + 3);
	q.push(tmp);
	
	a tmp1, tmp2;
	while (1) {
		if (q.front().arr[2] <= 0)break;
		tmp1.arr[0] = q.front().arr[0] - 1;
		tmp1.arr[1] = q.front().arr[1] - 3;
		tmp1.arr[2] = q.front().arr[2] - 9;
		sort(tmp1.arr, tmp1.arr + 3);
		tmp1.n = q.front().n + 1;

		tmp2.arr[0] = q.front().arr[0] - 3;
		tmp2.arr[1] = q.front().arr[1] - 1;
		tmp2.arr[2] = q.front().arr[2] - 9;
		sort(tmp2.arr, tmp2.arr + 3);
		tmp2.n = q.front().n + 1;

		q.push(tmp1);
		q.push(tmp2);
		q.pop();
	}

	printf("%d", q.front().n);
}
*/