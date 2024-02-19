#include <iostream>
#include <algorithm>

#define INF 1000000001

using namespace std;
int seq[100000];

int main(void)
{
    int N, left = 0, right, ans[2] = {INF, INF};

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }
    right = N - 1;
    sort(seq, seq + N);
    while (left < right)
    {
        if (seq[left] + seq[right] > 0)
        {
            if (seq[left] + seq[right] < abs(ans[0] + ans[1]))
            {
                ans[0] = seq[left];
                ans[1] = seq[right];
            }
            right--;
        }
        else if (seq[left] + seq[right] < 0)
        {
            if (abs(seq[left] + seq[right]) < abs(ans[0] + ans[1]))
            {
                ans[0] = seq[left];
                ans[1] = seq[right];
            }
            left++;
        }
        else
        {
            cout << seq[left] << " " << seq[right];
            return (0);
        }
    }
    cout << ans[0] << " " << ans[1];
}