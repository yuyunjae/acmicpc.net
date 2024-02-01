#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int> > stack;
int seq[1000001];
int F[1000001];
int ans[1000001];

int main(void)
{
    int N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
        F[seq[i]] += 1;
    }
    for (int i = 0; i < N; i++)
    {
        while (!stack.empty() && F[stack.back().first] < F[seq[i]])
        {
            ans[stack.back().second] = seq[i];
            stack.pop_back();
        }
        stack.push_back({seq[i], i});
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