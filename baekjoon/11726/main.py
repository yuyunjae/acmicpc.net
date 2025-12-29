# silver 3 - dp
import math

def main():
    n = int(input())
    dp = [0] * max(4,n + 1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2
    dp[3] = 3
    for i in range(4, n + 1):
        dp[i] = (dp[i - 3] + 2 * dp[i - 2]) % 10007
    print(dp[n])
    return 



if __name__=="__main__":
    main()