#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e11

using namespace std;

vector<tuple<long long int, long long int, long long int> > edge;
long long int   value[501];

int main(void)
{
    int N, M;
    long long int a, b ,c;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        edge.emplace_back(a, b, c);
    }
    for (int i = 2; i <= N; i++)
        value[i] = INF;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tie(a, b, c) = edge[j];
            if (value[a] != INF && value[b] > value[a] + c)
                value[b] = value[a] + c;
        }
    }
    for (int j = 0; j < M; j++)
    {
        tie(a, b, c) = edge[j];
        if (value[a] != INF && value[b] > value[a] + c)
        {
            cout << "-1\n";
            return (0);
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (value[i] == INF)
            cout << "-1\n";
        else
            cout << value[i] << '\n';
    }
}