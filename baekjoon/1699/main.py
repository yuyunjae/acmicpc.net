num = [i for i in range(100001)]
pw = [i*i for i in range(317)]
for i in range(1, 100001):
    a = int(pow(i, 0.5))
    for j in range(2, a + 1):
        num[i] = min(num[i], num[i - pw[j]] + 1)

N = int(input())

print(num[N])

