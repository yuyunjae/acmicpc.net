#include <iostream>
#include <vector>
#include <algorithm>

#define MAXI 1e9

using namespace std;

int obj[50];
int N, C;

void    dfs(int start, int end, vector<long long>& vec, long long sum)
{
    if (sum > MAXI)
        return ;
    if (start >= end)
    {
        vec.push_back(sum);
        return ;
    }
    dfs(start + 1, end, vec, sum); // 선택 x
    dfs(start + 1, end, vec, sum + obj[start]); //선택 o
}

int main(void) // MITM (Meet In The Middle) algorithm -> 브루트포스 알고리즘시 2^30(2 ^ N)이므로 반을 나눠서 계산후(2 ^ (N // 2)), C - vec_f[i]보다 같거나 작은 vec_e의 원소의 수를 ans에 더하는 방식.
{
    int ans = 0, val;

    vector<long long> vec_f;
    vector<long long> vec_e;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> obj[i];
    sort(obj, obj + N);
    dfs(0, N / 2, vec_f, 0);
    dfs(N / 2, N, vec_e, 0);
    sort(vec_e.begin(), vec_e.end());
    for (int i = 0; i < vec_f.size(); i++)
    {
        val = C - vec_f[i];
        ans += upper_bound(vec_e.begin(), vec_e.end(), val) - vec_e.begin();  // vec_e에서 val 보다 큰 숫자가 처음 나오는 인덱스 (iterator로 return - 초기 vec_f주소) 
    }
    cout << ans;
}