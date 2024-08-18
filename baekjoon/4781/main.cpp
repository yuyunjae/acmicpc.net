#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// typedef struct Compare {
//     bool operator()(pair<int, int> a, pair<int, int> b)
//     {
//         return (a.second < b.second);
//     }
// } Compare;

// bool compare(pair<int, int> a, pair<int, int> b)
// {
//     return (a.second < b.second);
// }

vector<pair<int, int> > candy;
unsigned long long int dp[10001];

int main(void)
{
    int num, money, cal, price;
    string temp;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        money = 0;
        cin >> num >> temp;
        if (num == 0 && temp == "0.00")
            return (0);
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] != '.')
                money = money * 10 + temp[i] - '0';
        }
        // cout << num << " " << money << endl;
        for (int i = 0; i < num; i++)
        {
            price = 0;
            cin >> cal >> temp;
            for (int j = 0; j < temp.length(); j++)
            {
                if (temp[j] != '.')
                    price = price * 10 + temp[j] - '0';
            }
            // cout << temp.length();
            candy.emplace_back(cal, price);
        }
        //sort(candy.begin(), candy.end(), compare);
        // for (auto i : candy)
        //     cout << i.first << " " << i.second << endl;

        for (auto i : candy)
        {
            for (int index = i.second; index <= money; index++)
            {
                dp[index] = max(dp[index], dp[index - i.second] + i.first);
            }
        }
        cout << dp[money] << '\n';
        candy.clear();
        for (int i = 0; i <= money; i++)
            dp[i] = 0;
    }
}