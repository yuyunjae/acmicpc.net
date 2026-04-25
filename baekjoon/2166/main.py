# use ccw algorithm

from sys import stdin


def solve():
    N = int(input())
    vertex = []
    for _ in range(N):
        x, y = map(int, stdin.readline().split())
        vertex.append([x, y])

    def ccw(a:list, b:list, c:list):
        return a[0] * c[1] + b[0] * a[1] + c[0] * b[1] - a[0] * b[1] - b[0] * c[1] - c[0] * a[1]
        
    

    answer = 0
    for i in range(1, len(vertex)):
        answer += ccw(vertex[0], vertex[i - 1], vertex[i])
    return abs(answer) / 2


if __name__=="__main__":
    print(f"{solve():.1f}")