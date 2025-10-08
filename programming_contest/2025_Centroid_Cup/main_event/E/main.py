from collections import deque
import heapq

n= int(input())
graph=[]
for i in range(n):
    line=input()
    ar=[]
    for l in range(len(line)):
        if line[l]=='R':
            start=[i,l]
            
        elif line[l]=='K':
            end=[i,l]
        ar.append(line[l])
    graph.append(ar)

mapp=[[1e9]*n for i in range(n)]
graph[start[0]][start[1]]='.'
mapp[start[0]][start[1]]=0

dx=[0,0,1,-1]
dy=[1,-1,0,0]
que=[(0,start)]


while que:
    cost,node=heapq.heappop(que)
    y,x=node[0],node[1]
    for t in range(4):
        nx = x
        ny = y
        while True:
            nx=nx+dx[t]
            ny=ny+dy[t]
            if 0<=nx<n and 0<=ny<n and graph[ny][nx] != "B":
                if graph[ny][nx]=='W':
                    if (mapp[y][x] + 1 <= mapp[ny][nx]):
                        heapq.heappush(que, (mapp[y][x]+1,[ny,nx]))
                        mapp[ny][nx]= mapp[y][x] + 1
                    break
                elif graph[ny][nx]=='K':
                    mapp[ny][nx]=min(mapp[y][x]+1, mapp[ny][nx])
                    
                    break
                elif graph[ny][nx]=='.':
                    if (mapp[y][x] + 1 <= mapp[ny][nx]):
                        heapq.heappush(que,(mapp[y][x]+1,[ny,nx]))
                        mapp[ny][nx]= mapp[y][x] + 1
                else:
                    break
            else:
                break
        # for i in graph:
        #     print(i)
        # print('\n\n')
            
            
if mapp[end[0]][end[1]]==1e9:
    print(-1)
else:
    print(mapp[end[0]][end[1]])

# for i in graph:
#     print(i)
            