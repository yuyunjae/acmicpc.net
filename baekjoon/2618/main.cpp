// 20m/s dp 배열을 몇 번째 사건을 어떤 경찰차가 처리했는가를 기준으로 다이나믹 프로그래밍을 이용해 풀었다
#include <iostream>
#include <stack>

using namespace std;

typedef struct s_point
{
    int x;
    int y;
} point;

int N, W;
point ac_point[1001];
int dp[1001][1001]; // [police1][police2]

int dfs(int police1, int police2)
{
    int accident, result1, result2;

    if (police1 == W || police2 == W)
        return (0);
    if (dp[police1][police2] != -1)
        return (dp[police1][police2]);
    
    accident = max(police1, police2) + 1;
    if (police1 == 0)
        result1 = abs(1 - ac_point[accident].y) + abs(1 - ac_point[accident].x);
    else
        result1 = abs(ac_point[police1].y - ac_point[accident].y) + abs(ac_point[police1].x - ac_point[accident].x);
    if (police2 == 0)
        result2 = abs(N - ac_point[accident].y) + abs(N - ac_point[accident].x);
    else
        result2 = abs(ac_point[police2].y - ac_point[accident].y) + abs(ac_point[police2].x - ac_point[accident].x);

    result1 += dfs(accident, police2); // 1번 경찰이 accident처리
    result2 += dfs(police1, accident); // 2번 경찰이 accident처리
    dp[police1][police2] = min(result1, result2);
    return (dp[police1][police2]);
}

int check_choice(int police1, int police2)
{
    int accident, result1, result2;

    if (police1 == W || police2 == W)
        return (0);
    
    accident = max(police1, police2) + 1;
    if (police1 == 0)
        result1 = abs(1 - ac_point[accident].y) + abs(1 - ac_point[accident].x);
    else
        result1 = abs(ac_point[police1].y - ac_point[accident].y) + abs(ac_point[police1].x - ac_point[accident].x);
    if (police2 == 0)
        result2 = abs(N - ac_point[accident].y) + abs(N - ac_point[accident].x);
    else
        result2 = abs(ac_point[police2].y - ac_point[accident].y) + abs(ac_point[police2].x - ac_point[accident].x);
    
    if (result1 + dp[accident][police2] < result2 + dp[police1][accident])
    {
        cout << "1\n";
        return (check_choice(accident, police2));
    }
    else
    {
        cout << "2\n";
        return (check_choice(police1, accident));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> W;
    for (int i = 1; i <= W; i++)
        cin >> ac_point[i].y >> ac_point[i].x;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < W; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << '\n';
    check_choice(0, 0);
}