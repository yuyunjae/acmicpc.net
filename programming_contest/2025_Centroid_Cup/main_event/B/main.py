# sol
h1,h2,h3=map(int,input().split())
n=int(input())
a = int((n + 1)//2)
# print(a)
print(n * h3 +h2 * a + h1 * (n % 2))

