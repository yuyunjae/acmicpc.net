#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    long long N, k;

    cin >> N >> k;

    long long left = 1, right = N * N, mid, count;

    while (left <= right)
    {
        count = 0;
        mid = (left + right) / 2;
        for (int i = 1; i <= N; i++)
        {
            count += min(mid / i, N);
            if (count >= k)
                break;        
        }
        if (count >= k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left;
}