# 완주하지 못한 선수
from collections import Counter

def solution(participant, completion):
    part = Counter(participant)
    com = Counter(completion)
    diff = part - com
    # print(diff)
    dict_diff = dict(diff)
    for i in dict_diff.keys():
        return i
    
    # 간단하게 하는 법
    # return list((Counter(participant) - Counter(completion)).keys())[0]