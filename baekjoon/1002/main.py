# sol 1002 simple
from sys import stdin
import math

def main():
    t = int(input())
    for _ in range(t):
        x1, y1, r1, x2, y2, r2 = map(int, stdin.readline().split())
        distance = math.sqrt((x1 - x2)**2 + (y1-y2)**2)
        if distance > r1 + r2:
            print(0)
            continue
        elif distance < r1 + r2:
            if r1 == r2 and distance == 0:
                print(-1)
                continue

            if r2 < r1:
                r1, r2 = r2, r1
                
            if distance + r1 > r2:
                print(2)
            elif distance + r1 < r2:
                print(0)
            else:
                print(1)
        else:
            print(1)

if __name__ == "__main__":
    main()