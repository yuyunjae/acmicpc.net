# https://school.programmers.co.kr/learn/courses/30/lessons/42579

# dictionary를 list로 바꾸면, key값으로 이루어진 list가 나온다! value가 들어가지 않음!
# sort에서 reverse=True는 명시한 변수들에서 뒤집는다.
def solution(genres, plays):
    gen = dict()
    sing_ply = dict()
    for i, (key, value) in enumerate(zip(genres, plays)):
        gen[key] = gen.get(key, 0) + value
        if key not in sing_ply:
            sing_ply[key] = list()
        sing_ply[key].append([value, i])
        
    g = list(gen.items())
    g.sort(key=lambda x: (x[1], x[0]), reverse=True)
    for val in sing_ply.values():
        val.sort(key=lambda x: (x[0], -x[1]) ,reverse=True) # 여기서 굳이 -x[1]을 안써도 상관없다. 파이썬은 stable sort를 하기 때문이다.
    answer = []
    # print(sing_ply)

    for genr in g:
        a = sing_ply[genr[0]][:2]
        # print(genr, a)

        for val in a:
            answer.append(val[1])
    
    return answer





# 다른 분 코드
# def solution(genres, plays):
#     answer = []

#     dic1 = {}
#     dic2 = {}

#     for i, (g, p) in enumerate(zip(genres, plays)):
#         if g not in dic1:
#             dic1[g] = [(i, p)]
#         else:
#             dic1[g].append((i, p))

#         if g not in dic2:
#             dic2[g] = p
#         else:
#             dic2[g] += p

#     for (k, v) in sorted(dic2.items(), key=lambda x:x[1], reverse=True):
#         for (i, p) in sorted(dic1[k], key=lambda x:x[1], reverse=True)[:2]:
#             answer.append(i)

#     return answer

