#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a, b;
    string ans = "";
    int check;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        ans += a[i];
        if (ans.size() >= b.size() && ans.back() == b.back())
        {
            check = true;
            for (int j = 0; j < b.size(); j++)
            {
                if (ans[ans.size() - 1 - j] != b[b.size() - 1 - j])
                {
                    check = false;
                    break ;
                }
            }
            if (check == true)
            {
                ans.erase(ans.size() - b.size(), b.size());
            }
        }
    }
    if (ans.empty())
        cout << "FRULA";
    else
        cout << ans;
}