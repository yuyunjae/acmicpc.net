# silver 3 - dp
# 테스트를 하기 전에 확실히 점검하고 하자.

def main(): 
    n = int(input())
    dp = [0] * max(4, n + 1)
    dp[1] = 1
    dp[2] = 3
    dp[3] = 5
    for i in range(4, n + 1):
        dp[i] = (2 * dp[i - 3] + 3 * dp[i - 2]) % 10007
    print(dp[n])

if __name__=="__main__":
    main()