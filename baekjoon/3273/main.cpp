#include <iostream>
#include <algorithm>

using namespace std;
int seq[100000];

int main(void)
{
    int n, x, left = 0, right, ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    cin >> x;
    right = n - 1;
    sort(seq, seq + n);
    while (left < right)
    {
        if (seq[left] + seq[right] == x)
        {
            ans++;
            left++;
            right--;
        }
        else if (seq[left] + seq[right] > x)
            right--;
        else
            left++;
    }
    cout << ans;
}