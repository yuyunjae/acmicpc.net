# sol 1003 fibonacci easy
from sys import stdin

def main():
    fibo = [0] * 41
    fibo[1] = 1
    for i in range(2, 41):
        fibo[i] = fibo[i - 1] + fibo[i - 2]

    t = int(stdin.readline().rstrip())
    for _ in range(t):
        n = int(stdin.readline().rstrip())
        if n == 0:
            print(1, 0)
        else:
            print(f'{fibo[n-1]} {fibo[n]}')


if __name__== "__main__":
    main()