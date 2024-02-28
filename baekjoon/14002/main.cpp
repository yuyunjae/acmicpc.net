#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> lis;
stack<int> ans;
int seq[1001];
int state[1001];

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
        if (lis[i] > seq[index])
        {
            lis[i] = seq[index];
            state[index] = i + 1;
        }
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


/* // 왜 틀리는지 모르겠다.. 아마 if (lis.back() <= seq[i] && seq[i] < before) 에서 문제가 생기는듯...
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> lis;
stack<int> ans;
int seq[1000];

void    lis_check(int value)
{
    int index;

    if (lis.empty() || lis.back() < value)
        lis.push_back(value);
    else
    {
        index = lower_bound(lis.begin(), lis.end(), value) - lis.begin();
        if (index >= 0 && index < lis.size())
            lis[index] = value;
    }
}

int main(void)
{
    int N, before = 1001;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> seq[i];
        lis_check(seq[i]);
    }
    cout << lis.size() << '\n';
    // for (auto i : lis)
    //     cout << i << ";";
    for (int i = N - 1; i >= 0; i--)
    {
        if (lis.empty())
            break ;
        if (lis.back() <= seq[i] && seq[i] < before)
        {
            ans.push(seq[i]);
            lis.pop_back();
            before = seq[i];
        }
    }  
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}

*/