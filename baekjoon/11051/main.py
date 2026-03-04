N, K = map(int, input().split())
dp = [[-1] * (N + 1) for i in range(N + 1)]

def comb(n, k):
    if n - k < k:
        k = n - k
    if dp[n][k] != -1:
        return dp[n][k]
    if k == 0:
        dp[n][k] = 1
        return dp[n][k]
    if k == 1:
        dp[n][k] = n
        return dp[n][k]
    
    dp[n][k] = (comb(n-1, k-1) % 10007 + comb(n-1, k) % 10007) % 10007
    return dp[n][k]
    
print(comb(N, K))