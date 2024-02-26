from sys import stdin #sol 724ms

N, M, K = map(int, stdin.readline().split())
number = [0]
a = 1
while a < N:
    a *= 2
heap = [0 for i in range(a * 2 + 1)]
    
def init_heap(start, end, index):
    if start == end:
        heap[index] = number[start]
        return (heap[index])
    mid = (start + end) // 2
    heap[index] = init_heap(start, mid, index * 2) + init_heap(mid + 1, end, index * 2 + 1)
    return (heap[index])

def update_heap(start, end, index, pos, diff):
    if start > pos or end < pos:
        return 
    heap[index] += diff
    if start == end:
        return
    mid = (start + end) // 2
    update_heap(start, mid, index * 2, pos, diff)
    update_heap(mid + 1, end, index * 2 + 1, pos, diff)
     
def print_sum(start, end, index, left, right):
    if start > right or end < left:
        return 0
    if start >= left and end <= right:
        return heap[index]
    mid = (start + end) // 2
    return (print_sum(start, mid, index * 2, left, right) + print_sum(mid + 1, end, index * 2 + 1, left, right))
    
for i in range(N):
    number.append(int(stdin.readline().rstrip()))
init_heap(1, N, 1)
for i in range(M + K):
    a, b, c = map(int, stdin.readline().split())
    if a == 1:
        diff = c - number[b]
        number[b] = c
        update_heap(1, N, 1, b, diff)
    elif a == 2:
        print(print_sum(1, N, 1, b, c))
    