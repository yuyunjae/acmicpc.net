# bronze1 - fibonacci

def main():
    n = int(input())
    dp = [0] * max(3, n+1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    print(dp[n])

if __name__=="__main__":
    main()  