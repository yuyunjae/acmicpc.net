#include <iostream>

#define INF (int)2e9

using namespace std;
int cum_sum[100001];

int main(void) //81% fail -> fixed! (just one number also consecutive numbers)
{
    int N, val, S, left = 0, right = 1, ans = INF;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    cin >> cum_sum[1];
    for (int i = 2; i <= N; i++)
    {
        cin >> val;
        cum_sum[i] = cum_sum[i - 1] + val; 
    }
    if (cum_sum[N] < S)
    {
        cout << "0";
        return (0);
    }
    while (right <= N && right >= left)
    {
        if (cum_sum[right] - cum_sum[left] >= S)
        {
            ans = min(ans, right - left);
            left++;
        }
        else
            right++;
        //cout << left << ":" << right << ":" << cum_sum[right] - cum_sum[left] << "::" << ans << endl;
    }
    if (ans == INF)
        cout << 0;
    else
        cout << ans;
}