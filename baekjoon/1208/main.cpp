#include <iostream>
#include <vector>
#include <algorithm>

#define MAXI 1e6

using namespace std;

int obj[50];
int N, S;

void    dfs(int start, int end, vector<int>& vec, int sum)
{
    // if (abs(sum) > MAXI)  // 바보다.. 1450번 문제는 물건의 무게를 다루기 때문에 음수가 있을 수 없지만, 해당 문제는 수열이므로 절대값이 S를 초과한 값과 다른 값을 더해 S가 될 수도 있다...
    //     return ;
    if (start >= end)
    {
        vec.push_back(sum);
        return ;
    }
    dfs(start + 1, end, vec, sum); // 선택 x
    dfs(start + 1, end, vec, sum + obj[start]); //선택 o
}

int main(void) // MITM (Meet In The Middle) algorithm -> 브루트포스 알고리즘시 2^40(2 ^ N)이므로 반을 나눠서 계산후(2 ^ (N // 2)), C - vec_f[i]보다 같거나 작은 vec_e의 원소의 수를 ans에 더하는 방식.
{
    long long int ans = 0;                                                                                        
    vector<int>::iterator val;

    vector<int> vec_f;
    vector<int> vec_e;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> obj[i];
    sort(obj, obj + N);
    dfs(0, N / 2, vec_f, 0);
    dfs(N / 2, N, vec_e, 0);
    sort(vec_e.begin(), vec_e.end());
    for (int i = 0; i < vec_f.size(); i++)
    {
        val = lower_bound(vec_e.begin(), vec_e.end(), S - vec_f[i]);
        if (*val == S - vec_f[i])
            ans += upper_bound(vec_e.begin(), vec_e.end(), S - vec_f[i]) - val;
    }
    if (S == 0)
        cout << ans - 1;
    else
        cout << ans;
}

/* // 다른 분의 코드지만, 256ms의 위 코드보다 훨씬빠른 8ms만에 해결한 모습. mp이라는 배열을 기가막히게 사용했음..
#include <iostream>
using namespace std;

const int BIAS = 3000000;

int N, S, arr[45], mid;
long long ans = 0;
int mp[BIAS*2+1] = {0};

void dfs1(int cur, int sum)
{
    if(cur == mid) {
        ++mp[BIAS+sum];
        return;
    }

    dfs1(cur+1, sum+arr[cur]);
    dfs1(cur+1, sum);
}

void dfs2(int cur, int sum)
{
    if(cur == N) {
        ans += mp[BIAS+(S-sum)];
        return;
    }
    dfs2(cur+1, sum+arr[cur]);
    dfs2(cur+1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for(int i=0; i<N; ++i) cin >> arr[i];
    
    mid = N/2;
    dfs1(0,0);
    dfs2(mid,0);
    if(S==0) --ans;
    cout << ans << '\n';
}
*/