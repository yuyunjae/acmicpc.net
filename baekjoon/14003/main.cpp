#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> lis;
stack<int> ans;
int seq[1000001];
int state[1000001];

void    lis_check(int index)
{
    int i;

    if (lis.empty() || lis.back() < seq[index])
    {
        lis.push_back(seq[index]);
        state[index] = lis.size();
    }
    else
    {
        i = lower_bound(lis.begin(), lis.end(), seq[index]) - lis.begin();
        lis[i] = seq[index];
        state[index] = i + 1;
    }
}

int main(void)
{
    int N, length;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> seq[i];
        lis_check(i);
    }
    length = lis.size();
    cout << length << '\n';
    for (int i = N - 1; i >= 0; i--)
    {
        if (length == 0)
            break ;
        if (state[i] == length)
        {
            ans.push(seq[i]);
            length -= 1;
        }
    }
    while (!ans.empty())
    {    
        cout << ans.top() << " ";
        ans.pop();
    }
}