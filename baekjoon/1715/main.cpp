#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main(void)
{
    int N, a, first, second, s, ans = 0;

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        pq.push(a);
    }
    while (!pq.empty())
    {
        first = pq.top();
        pq.pop();
        if (pq.empty())
            break ;
        second = pq.top();
        pq.pop();
        s = first + second;
        ans += s;
        pq.push(s);
    }
    cout << ans;
}