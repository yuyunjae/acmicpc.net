#include <iostream>
#include <algorithm>

using namespace std;

long long tree[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long M;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> tree[i];
    sort(tree, tree + N);

    long long left = 0;
    long long right = tree[N - 1];
    long long sum, mid, ans = 1000000001;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (tree[i] > mid)
                sum += tree[i] - mid;
            if (sum > M * 3)
                break;
        }
        if (sum >= M)
        {
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    cout << ans;
}