#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T, N, M, a, b;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> N >> M;
        for (int j = 0; j < M; j++)
        {
            cin >> a >> b;
        }
        cout << N - 1 << '\n';
    }
}