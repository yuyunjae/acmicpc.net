# 항상 반례를 체크하자 막 제출하지 말고..
# 기본적인 조건인 -1 출력 유뮤, k와 동전의 가치에 따른 예외처리 여부는 꼭 확인하기


from sys import stdin

n, k = map(int, stdin.readline().split())
coin = list()
dp = [1e6] * (k+1)
for i in range(n):
    temp = int(stdin.readline().rstrip())
    if temp <= k:
        coin.append(temp)

coin = list(set(coin))
# coin.sort(reverse=True)
# print(coin)

for c in coin:
    dp[c] = 1
    for i in range(c + 1, k + 1):
        if dp[i - c] != 1e6:
            dp[i] = min(dp[i], dp[i - c] + 1)
            # print(i, dp[i]) 

if dp[k] != 1e6:
    print(dp[k])
else:
    print(-1)