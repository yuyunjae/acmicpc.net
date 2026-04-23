# https://school.programmers.co.kr/learn/courses/30/lessons/42839s

from itertools import permutations

def solution(numbers):
    number_set = []
    for i in range(1, len(numbers) + 1):
        number_set.extend(permutations(numbers, i))
    temp_set = list(set(str(int("".join(a))) for a in number_set))
    # print(temp_set)
    
    
    num_list = [True] * 10000000
    num_list[0:2] = [False] * 2
    num_list[4::2] = [False] * 4999998
    max_num = int(10000000 ** 0.5 + 1)
    for i in range(3, max_num, 2):
        if num_list[i] == True:
            num_list[i*i::i] = [False] * len(num_list[i*i::i])
    
    answer = 0 
    for num in temp_set:
        if num_list[int(num)]:
            answer += 1
    

    return answer 


# from itertools import permutations
# def solution(n):
#     a = set()
#     for i in range(len(n)):
#         a |= set(map(int, map("".join, permutations(list(n), i + 1))))
#     a -= set(range(0, 2))
#     for i in range(2, int(max(a) ** 0.5) + 1):
#         a -= set(range(i * 2, max(a) + 1, i))
#     return len(a)