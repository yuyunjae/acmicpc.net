# 1. n²이 몇 개인가?
#    4000² = 1600만 → Python에서 이미 크다.

# 2. 중복 압축이 보장되는가?
#    값 범위 ±2²⁸ → 보장 안 됨.

# 3. dict key가 최악 몇 개인가?
#    최대 1600만 개 → Python dict로 매우 위험.

# 4. 정렬/투포인터 또는 이분탐색이 가능한가?
#    가능 → 그쪽이 더 안정적.

# 5. bisect
# bisect_left, bisect_right는 리스트가 오름차순으로 정렬되어있다고 가정
# 만약 내림차순일 경우에는 사용하면 안된다!


from sys import stdin

def solve():
    input = stdin.buffer.readline

    n = int(input())
    A, B, C, D = [], [], [], []

    for _ in range(n):
        a, b, c, d = map(int, input().split())
        A.append(a)
        B.append(b)
        C.append(c)
        D.append(d)

    left_list = []
    right_list = []

    for a in A:
        for b in B:
            left_list.append(a + b)

    for c in C:
        for d in D:
            right_list.append(c + d)

    left_list.sort()
    right_list.sort()

    left = 0
    right = len(right_list) - 1
    answer = 0

    while left < len(left_list) and right >= 0:
        total = left_list[left] + right_list[right]

        if total < 0:
            left += 1

        elif total > 0:
            right -= 1

        else:
            left_val = left_list[left]
            right_val = right_list[right]

            left_count = 0
            while left < len(left_list) and left_list[left] == left_val:
                left += 1
                left_count += 1

            right_count = 0
            while right >= 0 and right_list[right] == right_val:
                right -= 1
                right_count += 1

            answer += left_count * right_count

    return answer

if __name__ == "__main__":
    print(solve())




# pypy3로 겨우 통과... O(n^2), 1189756kb	9540ms
# from sys import stdin


# def solve():
#     n = int(input())
#     li_a, li_b, li_c, li_d = list(), list(), list(), list()
#     answer = 0
#     for _ in range(n):
#         a, b, c, d = map(int, stdin.readline().split())
#         li_a.append(a)
#         li_b.append(b)
#         li_c.append(c)
#         li_d.append(d)

#     left_dict = dict()
#     for a in li_a:
#         for b in li_b:
#             s = a+b
#             left_dict[s] = left_dict.get(s, 0) + 1

#     for c in li_c:
#         for d in li_d:
#             answer += left_dict.get(-(c+d), 0)

#     return answer


# if __name__=="__main__":
#     print(solve())





# 시간초과 O(n^2)를 여러번 해서 그런 듯..
# from collections import Counter
# from sys import stdin


# def solve():
#     n = int(input())
#     li_a, li_b, li_c, li_d = list(), list(), list(), list()
#     answer = 0
#     for _ in range(n):
#         a, b, c, d = map(int, stdin.readline().split())
#         li_a.append(a)
#         li_b.append(b)
#         li_c.append(c)
#         li_d.append(d)

#     left_counter = Counter()
#     right_counter = Counter()
    

#     def make_counter(list_left: list, list_right:list , count: Counter):
#         for a in list_left:
#             for b in list_right:
#                 count[a + b] += 1

#     make_counter(li_a, li_b, left_counter)
#     make_counter(li_c, li_d, right_counter)

#     if len(left_counter) > len(right_counter):
#         left_counter, right_counter = right_counter, left_counter

#     for val in left_counter:
#         if -val in right_counter:
#             answer += left_counter[val] * right_counter[-val]

#     return answer


# if __name__=="__main__":
#     print(solve())