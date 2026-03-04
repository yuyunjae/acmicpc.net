from sys import stdin


dp = [0 for _ in range(1000)]

N = int(stdin.readline().rstrip())
p = list(map(int, stdin.readline().split()))


for i in range(N):
    for j in range(i):
        if p[j] < p[i]:
            dp[i] = max(dp[i], dp[j])

    dp[i] += p[i]
print(max(dp))