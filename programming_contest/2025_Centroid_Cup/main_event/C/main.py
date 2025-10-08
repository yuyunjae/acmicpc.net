# sol
n,m=map(int,input().split())

graph=[]
for _ in range(n):
    graph.append(input())
    

dx=[0,0,1,-1]
dy=[1,-1,0,0]
answer=0

for i in range(n):
    for j in range(m):
        if graph[i][j]=='X':
            for t in range(4):
                if 0<=i+dy[t]<n and 0<=j+dx[t]<m and graph[i+dy[t]][j+dx[t]]=='Y':
                    answer+=1
                    
print(answer)