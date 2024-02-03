#include <iostream>
#include <stack>

using namespace std;

stack<int> index_stack;
int h[100002];

int main(void)
{
    int N, height;
    long long int ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> h[i];
    index_stack.push(0);
    for (int i = 1; i <= N + 1; i++)
    {
        while (!index_stack.empty() && h[index_stack.top()] > h[i])
        {
            height = index_stack.top();
            index_stack.pop();
            ans = max(ans, (long long int)h[height] * (i - index_stack.top() - 1));
        }
        index_stack.push(i);
    }
    cout << ans;
}