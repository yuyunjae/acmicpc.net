// 고민하는데 너무 오래 걸렸다.. a, b, c값이 있을 때, a와 b만 체크한다면 c의 값은 확정적으로 알 수 있으므로 bfs로 방문 가능한 모든 경우를 체크하고,
// a+b+c인 sum을 통해서 visit[sum/3][sum/3]이 방문했다면, c는 마찬가지로 sum/3이 되므로 답이 1이 나온다. 나머지는 0으로 처리..
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

queue<tuple<int, int, int> > qu;
bool visit[1501][1501];

int main(void)
{
    int a, b, c, cases[3];
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    if ((a + b + c) % 3)
        cout << 0;
    else if (a == b && b == c)
        cout << 1;
    else
    {
        qu.push(make_tuple(a, b, c));
        while (!qu.empty())
        {
            tie(cases[0], cases[1], cases[2]) = qu.front();
            qu.pop();
            sort(cases, cases + 3);

            a = cases[0] + cases[0];
            b = cases[1] - cases[0];
            c = cases[2];
            if (!visit[a][b])
            {
                visit[a][b] = true;
                visit[b][a] = true;
                qu.push(make_tuple(a, b, c));
            }

            a = cases[0] + cases[0];
            b = cases[2] - cases[0];
            c = cases[1];
            if (!visit[a][b])
            {
                visit[a][b] = true;
                visit[b][a] = true;
                qu.push(make_tuple(a, b, c));
            }


            a = cases[1] + cases[1];
            b = cases[2] - cases[1];
            c = cases[0];
            if (!visit[a][b])
            {
                visit[a][b] = true;
                visit[b][a] = true;
                qu.push(make_tuple(a, b, c));

            }
        }
        if (visit[(a + b + c)/3][(a + b + c)/3])
            cout << 1;
        else
            cout << 0;
    }
}