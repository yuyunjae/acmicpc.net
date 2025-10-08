# sol
n=int(input())
four=[[4,2,3,2],[3,1,1,4]]
five=[[4,1,1,2,5],[5,3,2,4,3]]
ar_start=[[4,2],[3,1]]
ar_end=[[3,2],[1,4]]

answer=[]
answer2=[]

if n==1:
    answer=[1]
    answer2=[1]
elif n%4==0:
    tmp=n//4-1
    while tmp>0:
        for num in ar_start[0]:
            answer.append(num+4*tmp)
        for num in ar_start[1]:
            answer2.append(num+4*tmp)
        tmp-=1
    answer+=four[0]
    answer2+=four[1]
    while tmp<n//4-1:
        tmp+=1
        for num in ar_end[0]:
            answer.append(num+4*tmp)
        for num in ar_end[1]:
            answer2.append(num+4*tmp)
 
elif n%4==1:
    tmp=n//4-1
    while tmp>0:
        for num in ar_start[0]:
            answer.append(num+1+4*tmp)
        for num in ar_start[1]:
            answer2.append(num+1+4*tmp)
        tmp-=1
    answer+=five[0]
    answer2+=five[1]
    while tmp<n//4-1:
        tmp+=1
        for num in ar_end[0]:
            answer.append(num+1+4*tmp)
        for num in ar_end[1]:
            answer2.append(num+1+4*tmp)
else:
    print(-1)

print(*answer)   
print(*answer2)