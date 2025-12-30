# silver 1
from sys import stdin

def main():
    N = int(input())
    answer = 1
    for i in range(1, N + 1):
        answer = int(answer * (9 + i) // i)
    print(answer % 10007)

if __name__=="__main__":
    main()