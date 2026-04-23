# https://school.programmers.co.kr/learn/courses/30/lessons/43165

from collections import Counter
def solution(numbers, target):
    
    def dfs(idx, maxi, val, num_li: list, li: list):
        if idx == maxi:
            li.append(val)
            return 
        dfs(idx + 1, maxi, val + num_li[idx], num_li, li)
        dfs(idx + 1, maxi, val - num_li[idx], num_li, li)     
        return
    
    
    
    mid = len(numbers) // 2
    left, right = list(), list()
    dfs(0, mid, 0, numbers, left)
    dfs(mid, len(numbers), 0, numbers, right)
    left = Counter(left)
    # print(left, right)
    answer = 0
    for i in right:
        answer += left.get(i - target, 0)
        
    return answer



# def solution(numbers, target):
#     if not numbers and target == 0 :
#         return 1
#     elif not numbers:
#         return 0
#     else:
#         return solution(numbers[1:], target-numbers[0]) + solution(numbers[1:], target+numbers[0])

