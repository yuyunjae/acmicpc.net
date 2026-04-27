# two pointer 120ms
# min_mix = 지금까지 최고 점수
# mix의 부호 = 지금 운전대를 왼쪽으로 틀지 오른쪽으로 틀지


from sys import stdin

def solve():
    N = int(stdin.readline().strip())
    liqu = list(map(int, stdin.readline().split()))
    left, right = 0, N - 1       
    ans1, ans2 = liqu[0], liqu[N - 1]
    min_mix = abs(ans1 + ans2)

    while left < right:
        mix = liqu[left] + liqu[right]
        if abs(mix) < min_mix:
            min_mix = abs(mix)
            ans1, ans2 = liqu[left], liqu[right]

        if mix > 0:
            right -= 1
        elif mix < 0:
            left += 1
        else:
            break

    return ans1, ans2

if __name__=="__main__":
    print(*solve(), sep=" ")