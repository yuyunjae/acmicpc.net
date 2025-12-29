# silver 3 - dp
from sys import stdin
def main():
    N = int(stdin.readline().rstrip())
    dp = [0] * (N + 6)
    for i in range(0, N):
        t, p = map(int, stdin.readline().split())
        if i > 0:
            dp[i] = max(dp[i - 1], dp[i])
        dp[i + t] = max(dp[i + t], dp[i] + p)
    print(max(dp[:N + 1]))

if __name__=="__main__":
    main()



# solution by someone
# from sys import stdin

# it = stdin.readline

# n = int(it())
# l = [list(map(int, it().split())) for i in range(n)]
# dp = [0] * (n + 1)
# i = 0
# for i in range(n):
#     for j in range(i + l[i][0], n + 1):
#         if dp[j] < dp[i] + l[i][1]:
#             dp[j] = dp[i] + l[i][1]
# print(dp[-1])