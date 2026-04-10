# https://school.programmers.co.kr/learn/courses/30/lessons/42747
# from bisect import bisect_left
# bisect_left, bisect_right 잘 기억하기
# bisect_right는 해당 숫자 가장 오른쪽 !!!! 바로 다음 !!!! 위치의 index
# bisect_left는 해당 숫자 가장 왼쪽 위치의 index
# 이렇게 된 이유는 return해주는 index위치로 insert했을 때 오류가 없기 위함
# 1 4 4 4 6 <= 2, 5넣을때 생각해보기 


from bisect import bisect_left

def solution(citations):
    citat = sorted(citations)
    print(citat)
    left, right = 0, 1000
    answer = 0
    while left <= right:
        mid = (left + right) // 2
        if len(citat) - bisect_left(citat, mid) >= mid:
            left = mid + 1
            answer = mid
        else:
            right = mid - 1
    return answer