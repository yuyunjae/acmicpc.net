#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int> > stack;
int ans[1000001];

int main(void)
{
    int N;
    int num;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        while (!stack.empty() && stack.back().first < num)
        {
            ans[stack.back().second] = num;
            stack.pop_back();
        }
        stack.push_back({num, i});
    }
    while (!stack.empty())
    {
        ans[stack.back().second] = -1;
        stack.pop_back();
    }
    for(int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}