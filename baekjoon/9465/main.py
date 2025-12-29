# silver 1 - dp, 풀이 법은 바로 생각났는데 꼼꼼하지를 못함.
# n = 1 일 때, val[1][0] 이런거 접근 못하도록 해야함 (out of index error)

from sys import stdin

def main():
    T = int(stdin.readline().rstrip())
    for _ in range(T):
        n = int(stdin.readline().rstrip())
        val = list()
        val.append(list(map(int, stdin.readline().split())))
        val.append(list(map(int, stdin.readline().split())))
        # print(val)
        dp = [[0, 0] for _ in range(n + 1)]
        # print(dp)
        dp[0][0], dp[0][1] = val[0][0], val[1][0]
        if n > 1:
            dp[1][0] = dp[0][1] + val[0][1]
            dp[1][1] = dp[0][0] + val[1][1]
        for i in range(2, n):
            dp[i][0] = max(dp[i - 2][1], dp[i - 1][1]) + val[0][i]
            dp[i][1] = max(dp[i - 2][0], dp[i - 1][0]) + val[1][i]
        print(max(dp[n-1][0], dp[n-1][1]))

if __name__=="__main__":
    main()




# 장인의 풀이
# import sys
# input = sys.stdin.readline


# x = int(input())
# for i in range(x) :
#   n = int(input())
#   x1 = list(map(int, input().split()))
#   x2 = list(map(int, input().split()))
#   if n == 1 :
#     print(max(x1[0], x2[0]))
#     continue
#   x1[1] += x2[0]
#   x2[1] += x1[0]
#   for j in range(2, n) :
#     x1[j] += max(x2[j-2], x2[j-1])
#     x2[j] += max(x1[j-2], x1[j-1])
#   print(max(x1[n-1], x2[n-1]))