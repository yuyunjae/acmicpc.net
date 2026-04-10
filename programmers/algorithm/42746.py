# https://school.programmers.co.kr/learn/courses/30/lessons/42746
# from functools import cmp_to_key 외우기!
# 그리고 compare함수에서는 꼭 return 0 (같을 때)도 구분해 두어야함.
# 마지막으로 "000000" 이런 경우도 예외처리 해줘야함.... "00000" => "0"
# 라이브러리 사용 조건
# comparator 규약
# 엣지 케이스
from functools import cmp_to_key

def solution(numbers):
    str_numbers = list(map(str, numbers))
    def compare(a: str, b: str):
        if a + b > b + a:
            return -1
        elif a + b < b +a:
            return 1
        return 0
    str_numbers.sort(key=cmp_to_key(compare))
    # print(str_numbers)
    answer = "".join(str_numbers)
    return "0" if answer[0] == "0" else answer