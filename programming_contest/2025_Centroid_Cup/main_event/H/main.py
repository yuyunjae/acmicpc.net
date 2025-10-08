# sol
n=int(input())

tetris=['daaa',
'ddab',
'dcbb',
'cccb']

if n%4 != 0:
    print(-1)
else:
    for i in range(n//4):
        for j in range(4):
            print(tetris[j]*(n//4))
    
