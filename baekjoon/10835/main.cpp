// dfs만읊 생각했는데, dp를 이용하니 100점을 맞을 수 있었다.. 문제를 풀기 위한 효율적인 알고리즘을 생각해낼 수 있는 능력을 길러야 할 것 같다.
#include <iostream>

using namespace std;

int N, left_arr[2000], right_arr[2000], dp[2000][2000];

int dfs(int left_index, int right_index)
{
    if (left_index >= N || right_index >= N)
        return 0;
    if (dp[left_index][right_index] != -1)
        return dp[left_index][right_index];


    if (left_arr[left_index] <= right_arr[right_index])
        dp[left_index][right_index] = max(dfs(left_index + 1, right_index), dfs(left_index + 1, right_index + 1));
    else
        dp[left_index][right_index] = dfs(left_index, right_index + 1) + right_arr[right_index];
    return dp[left_index][right_index];
}

int main(void)
{
    int left_index = 0, right_index = 0, point = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> left_arr[i];
    for (int i = 0; i < N; i++)
        cin >> right_arr[i];
    for (int i = 0; i < N; i++)
    {
        for(int  j = 0; j < N; j++)
            dp[i][j] = -1;
    }
    cout << dfs(0, 0);
}



// 64/100점 풀이 (time over)
// #include <iostream>

// using namespace std;

// int N, left_arr[2000], right_arr[2000];

// int dfs(int left_index, int right_index, int point)
// {
//     while (left_index <= N && right_index <= N)
//     {
//         if (left_arr[left_index] > right_arr[right_index])
//         {
//             point += right_arr[right_index];
//             right_index++;
//         }
//         else
//         {
//             if (left_index + 1 <= N && left_arr[left_index + 1] > right_arr[right_index])
//                 left_index++;
//             else
//             {
//                 return max(dfs(left_index + 1, right_index + 1, point), dfs(left_index + 1, right_index, point));    
//             }
//         }
//     }
//     return point;
// }

// int main(void)
// {
//     int left_index = 0, right_index = 0, point = 0;
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N;
//     for (int i = 0; i < N; i++)
//         cin >> left_arr[i];
//     for (int i = 0; i < N; i++)
//         cin >> right_arr[i];
//     cout << dfs(0, 0, 0);
// }