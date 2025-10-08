# sol

import math
from collections import deque

T=int(input())
for _ in range(T):
    N=int(input())
    ar=deque([1])
    for i in range(2,N+1):
        if int(math.sqrt(i+ar[-1]))!=math.sqrt(i+ar[-1]):
            ar.append(i)
        else:
            ar.appendleft(i)
            
    print(*ar)
