# same as 1038 감소하는 수
import itertools
N = int(input())
a = [9,8,7,6,5,4,3,2,1,0]
dec_num = list()
for i in range(1, 11):
    tmp = itertools.combinations(a, i)
    for k in tmp:
        dec_num.append(''.join(map(str, k)))
    if len(dec_num) > N:
        break
dec_num = list(map(int, dec_num))
dec_num.sort()
if N > len(dec_num):
    print(-1)
else:
    print(dec_num[N - 1])