# 2500ms dict을 이용.. bfs 느낌인데, 아래 코드보다 비효율적임
from sys import stdin
# from collections import 

def solve():
    n = int(stdin.readline().strip())
    students = list(map(int, stdin.readline().split()))
    answer = 0
    visit = [False] * n

    for i in range(len(students)):
        if visit[i]:
            continue
        visit[i] = True
        idx = 0
        path = dict()
        path[i] = idx
        idx += 1
        stu = i
        while (students[stu] - 1) not in path and visit[students[stu] -1] == False:
            stu = students[stu] - 1
            path[stu] = idx
            idx += 1
            visit[stu] = True
        # print()
        
        # cycle 있음
        if (students[stu] - 1) in path:
            answer += path[students[stu] - 1]
            # print(f"if answer = {answer}, i = {i + 1}, added = {path[students[stu] - 1]}, end = {students[stu]}")
        
        # 없음
        else:
            answer += len(path)
            # print(f"else answer = {answer}, i = {i + 1}, added = {len(path)}, end = {students[stu]}")

    return answer

    

if __name__== "__main__":
    T = int(stdin.readline().strip())
    for _ in range(T):
        print(solve())




# 다른 사람의 코드 800ms
# 나를 가리키는 노드가 없으면, 해당 노드를 시작지점으로 하고, 
# deque를 이용해서 해당 노드 queue에 넣고 edge제거하면서 edge가 없는 node가 생기면 반복


# import sys
# #if sys.platform == 'win32':         # window 환경에서만 동작
# #    sys.stdin = open('input05.txt')      # input data를 text 파일에서 읽어오기
# input = sys.stdin.readline # 백준에서는 해당 부분으로 인해 시간이 차이가 날 수 있으니 참고

# from collections import deque

# for _ in range(int(input())):
#     n = int(input())
#     tmp = list(map(int, input().split()))
#     que = [0] * n

#     for t in tmp:
#         que[t-1] += 1

#     arr = deque()
#     for idx, q in enumerate(que):
#         if q == 0:
#            arr.append(idx+1)

#     cnt = len(arr)
#     # print('que', que)
#     # print('arr', arr)

#     while arr:
#         next = arr.popleft() # 2
#         que[tmp[next-1]-1] -= 1
#         # print(que)
#         if que[tmp[next-1]-1] == 0:
#             arr.append(tmp[next-1])
#             cnt += 1

#     print(cnt)
