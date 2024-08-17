// 다이아라 어렵다... greedy방식으로 풀었지만, 더 좋은 풀이가 무조건 있을 것이다.
#include <iostream>

using namespace std;

int main(void)
{
    int N, noodle[10000], mini;
    unsigned long long int ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> noodle[i];
    for (int i = 0; i < N - 2; i++)
    {
        while (noodle[i])
        {
            mini = noodle[i];
            if (noodle[i + 1])
            {
                mini = min(noodle[i], noodle[i + 1]);
                if (noodle[i + 2])
                {
                    if (noodle[i] >= noodle[i + 1] || noodle[i + 1] <= noodle[i + 2])
                    {
                        mini = min(mini, noodle[i + 2]);
                        ans += mini * 7;
                        noodle[i + 2] -= mini;
                    }
                    else
                    {
                        mini = 1;
                        ans += mini * 5;
                    }
                }
                else
                    ans += mini * 5;
                noodle[i + 1] -= mini;
            }
            else
                ans += mini * 3;
            noodle[i] -= mini;
        }
    }
    while (noodle[N - 2])
    {
        mini = noodle[N - 2];
        if (noodle[N - 1])
        {
            mini = min(mini, noodle[N - 1]);
            ans += mini * 5;
            noodle[N - 1] -= mini;
        }
        else
            ans += mini * 3;
        noodle[N - 2] -= mini;
    }
    ans += 3 * noodle[N - 1];
    cout << ans;
}