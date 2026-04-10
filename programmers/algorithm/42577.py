# https://school.programmers.co.kr/learn/courses/30/lessons/42577
# 조건을 자세히 보자.. 같은 전화번호는 없기 때문에, != 조건으로 자기 자신을 구분해냄.
# O(n^2 * 문자열 길이) -> timeover
# def solution(phone_book):
#     # answer = True
#     for i, number in enumerate(phone_book):
#         for phone_n in phone_book:
#             # print(f'{i} {number} {phone_n}')
#             if phone_n != number and phone_n.startswith(number):
#                 return False
#     return True


# O(nlogn or n * 문자열 길이)
def solution(phone_book):
    # answer = True
    phone = list(phone_book)
    phone.sort()
    for i in range(0,len(phone) -1):
        if phone[i + 1].startswith(phone[i]):
            return False
        
    return True