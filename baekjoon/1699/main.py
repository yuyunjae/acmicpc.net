num = [i for i in range(100001)]
pw = [i*i for i in range(317)]
for i in range(1, 100001):
    a = int(pow(i, 0.5))
    for j in range(2, a + 1):
        num[i] = min(num[i], num[i - pw[j]] + 1)

N = int(input())

print(num[N])



# other's code

# import math
# n = int(input())

# def solution(n):
#     if math.isqrt(n) ** 2 == n:
#         return 1

#     for i in range(1, int(n ** 0.5) + 1):
#         remain = n - (i**2)
#         if math.isqrt(remain) ** 2 == remain:
#             return 2
        
#     # 르장드르
#     m = n
#     while m % 4 == 0:
#         m //= 4
#     if m % 8 == 7:
#         return 4

#     return 3

# print(solution(n))


# 라그랑주의 네 제곱수 정리 (Lagrange's Four-Square Theorem): 
# "모든 자연수는 넷 혹은 그 이하의 소수 제곱수의 합으로 표현할 수 있다."
# 👉 즉, 이 문제의 정답은 무조건 1, 2, 3, 4 중 하나라는 뜻입니다. (5개 이상 필요한 숫자는 우주상에 존재하지 않습니다.)


# 르장드르의 세 제곱수 정리 (Legendre's Three-Square Theorem):
# "어떤 자연수가 만약 $n = 4^a(8b + 7)$ 형태 (단, $a, b$는 0 이상의 정수)를 띈다면, 
# 그 수는 3개 이하의 제곱수의 합으로 표현할 수 없다."
# 👉 즉, 숫자가 $4^a(8b + 7)$ 형태라면 정답은 무조건 '4'가 된다는 뜻입니다.