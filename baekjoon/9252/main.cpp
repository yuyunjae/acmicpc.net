#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int dp[1001][1001];

int main(void) //https://gusdnr69.tistory.com/192 참고..
{
    int a_len, b_len, num;
    
    cin >> a >> b;
    a_len = a.length();
    b_len = b.length();
    for (int i = 1; i <= a_len; i++)
    {
        for(int j = 1; j <= b_len; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 단순히 길이를 구하는 것이었으면 1차원 배열(dp)로 가능했을 듯.
        }
    }
    num = dp[a_len][b_len];
    cout << num;
    if (num)
    {
        string ans = "";

        cout << '\n';
        while (a_len > 0 && b_len > 0) // a_len > 0 || b_len > 0 으로 작성하니까 바로 틀림.. segfault
        {
            if (dp[a_len][b_len] == dp[a_len][b_len - 1])
                b_len -= 1;
            else if (dp[a_len][b_len] == dp[a_len - 1][b_len])
                a_len -= 1;
            else if (dp[a_len][b_len] != dp[a_len - 1][b_len - 1])
            {
                ans += a[a_len - 1];
                a_len -= 1;
                b_len -= 1;
            }
            // else // 어처피 dp[a_len - 1][b_len - 1]이 dp[a_len][b_len - 1]이나 dp[a_len - 1][b_len]보다 클 경우가 없음..
            //     b_len -= 1;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}