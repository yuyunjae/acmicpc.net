# silver 1 - dp
from sys import stdin


def main():
    N = int(stdin.readline().rstrip())
    parr = list(map(int, stdin.readline().split()))
    dp = [0] * (N + 1)
    for i in range(N):
        cards = i + 1
        for j in range(cards, N + 1):
            dp[j] = max(dp[j], dp[j - cards] + parr[i])
        # print(dp[N])
    print(dp[N])
        

if __name__=="__main__":
    main()