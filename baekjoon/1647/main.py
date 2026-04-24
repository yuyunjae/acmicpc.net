# Kruskal MST + union find (6000ms)
# 부모가 겹치지 않으면 연결
# 기본적으로 주어진 edge들은 모든 node를 이동할 수 있도록 문제에거 주어졌기 떄문에
# 부모가 겹치지 않는 모두 연결하고 마지막 연결만 제외하면 됨.

# 만약 위 조건이 보장되지 않는다면 MSF(Minimum Spanning Forest) 문제

from sys import stdin
import heapq

def solve():
    N, M = map(int, stdin.readline().split())
    path = []
    union_list = [i for i in range(N + 1)]
    answer = 0
    current_expence = 0

    def find(union_list, num):
        num_parent = union_list[num]
        if num_parent != num:
            num_parent = find(union_list, num_parent)
        return num_parent

    def union(union_list, a_parent, b_parent):
        if a_parent >= b_parent:
            union_list[a_parent] = b_parent
        else:
            union_list[b_parent] = a_parent        


    for _ in range(M):
        a, b, expence = map(int, stdin.readline().split())
        heapq.heappush(path, [expence, a, b])

    while path:
        expence, a, b = heapq.heappop(path)
        # print(f"expence: {expence}, a = {a}, b = {b} ")
        a_parent = find(union_list, a)
        b_parent = find(union_list, b)
        if a_parent != b_parent:
            answer += expence
            current_expence = expence
            union(union_list, a_parent, b_parent)
            

    return answer - current_expence

if __name__=="__main__":
    print(solve())






# 5152ms (find 조금 더 최적화)
# from sys import stdin
# import heapq

# def solve():
#     N, M = map(int, stdin.readline().split())
#     path = []
#     union_list = [i for i in range(N + 1)]
#     answer = 0
#     current_expence = 0

#     def find(num):
#         if union_list[num] != num:
#             union_list[num] = find(union_list[num])
#         return union_list[num]

#     def union(a_parent, b_parent):
#         if a_parent >= b_parent:
#             union_list[a_parent] = b_parent
#         else:
#             union_list[b_parent] = a_parent        


#     for _ in range(M):
#         a, b, expence = map(int, stdin.readline().split())
#         heapq.heappush(path, [expence, a, b])

#     while path:
#         expence, a, b = heapq.heappop(path)
#         # print(f"expence: {expence}, a = {a}, b = {b} ")
#         a_parent = find(a)
#         b_parent = find(b)
#         if a_parent != b_parent:
#             answer += expence
#             current_expence = expence
#             union(a_parent, b_parent)
            

#     return answer - current_expence

# if __name__=="__main__":
#     print(solve())
