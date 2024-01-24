#include <iostream>
#include <algorithm>

using namespace std;

int wifi[200001];


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C, ans;

    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> wifi[i];
    }
    sort(wifi, wifi + N);
    ans = wifi[N - 1] - wifi[0];
    
    int left = 1;
    int right = wifi[N - 1] - wifi[0];
    int mid;

    while (left <= right)
    {
        int count = 1;
        int point = wifi[0];

        mid = (left + right) / 2;
        for (int i = 1; i < N; i++)
        {
            if (mid <= wifi[i] - point)
            {
                point = wifi[i];
                count++;
            }
            if (count == C)
                break;
        }
        if (count == C)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << ans;
}