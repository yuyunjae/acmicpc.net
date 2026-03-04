# 가장 긴 감소하는 부분수열 == list를 거꾸로 뒤집어서 생각해보면, 가장 긴 증가하는 부분수열을 구하는 것이므로 

from sys import stdin
import bisect


N = int(stdin.readline().rstrip())
p = list(map(int, stdin.readline().split()))

reduce_p = [p[-1]]
for i in range(N-2, -1, -1):
    # print(f'reduce_p {reduce_p}, i = {i}, p[i] = {p[i]}')
    if p[i] > reduce_p[-1]:
        reduce_p.append(p[i])
    else:
        idx = bisect.bisect_left(reduce_p, p[i])
        reduce_p[idx] = p[i]
print(len(reduce_p))