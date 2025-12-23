# 문제를 너무 어렵게 생각했다.
# 그냥 n번째 = [1 || n-1번째 조합] + [2 || n-2번째 조합] + [3 || n-3번째 조합] 이면 모든 n번째 숫자의 조합을 표현할 수 있음.

from sys import stdin
input = stdin.readline

dp = [0] * 12
dp[0] = 0
dp[1] = 1
dp[2] = 2
dp[3] = 4
for i in  range(4, 12):
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    # print(dp[i])

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    if n < 1:
        print(0)
    else:
        print(dp[n])

    