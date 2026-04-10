# https://school.programmers.co.kr/learn/courses/30/lessons/42578

# 문제를 잘 이해해야함
# 지금처럼 하나만 입는 경우 +  나머지를 구하는게 아니라
# 어떤 부위에 대해서 (종류 + 1(안입는 경우))를 구하고 이를 곱해나가면서 구해야함
# 마지막에 그 어떤 것도 안입는 경우인 1을 빼줘야 함.

# wrong case
# from collections import defaultdict

# def solution(clothes):
#     answer = 0
#     answer += len(clothes)
#     cloth = defaultdict(int)
#     for val, key in clothes:
#         cloth[key] += 1
   

#     if answer == 0 or len(list(cloth.values())) == 1:
#         return answer
#     cloth_case = 1
#     for val in cloth.values():
#         cloth_case *= val
#     return answer + cloth_case



# good case
# using defaultdict
# from collections import defaultdict

# def solution(clothes):
#     cloth = defaultdict(int)
#     for val, key in clothes:
#         cloth[key] += 1
#     answer = 1
#     for val in cloth.values():
#         answer *= val + 1
#     return answer -1



def solution(clothes):
    cloth = {}

    for _, kind in clothes:
        cloth[kind] = cloth.get(kind, 0) + 1

    answer = 1
    for cnt in cloth.values():
        answer *= (cnt + 1)

    return answer - 1