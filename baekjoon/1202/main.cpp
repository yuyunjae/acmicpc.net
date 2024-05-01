#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> bag;
vector <pair<int, int> > jewel;
priority_queue <int> jew;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}

int main(void)
{
    int N, K, price, wei, cap;
    long long int ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> wei >> price;
        jewel.emplace_back(wei, price);
    }
    for (int i = 0; i < K; i++)
    {
        cin >> cap;
        bag.push_back(cap);
    }
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    int j = 0;
    for (int i = 0; i < K; i++)
    {
        while (j < N && jewel[j].first <= bag[i])
            jew.push(jewel[j++].second);
        if (!jew.empty())
        {
            ans += jew.top();
            jew.pop();
        }
    }
    cout << ans;
}