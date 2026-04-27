# palindrome 1136ms
# find palindrome O(n^2)
# dp O(n^2)

def solve():
    string = str(input().strip())
    palindrome = [list() for i in range(len(string))]
    dp = [2501] * len(string)
    for mid in range(len(string)):

        # 홀수 palindrome A, AAA, ABCBA
        start, end = mid, mid
        while start > -1 and end < len(string):
            if string[start] == string[end]:
                palindrome[start].append(end)
                start -= 1 
                end += 1 
            else:
                break

        # 짝수 palindrome BB, AAAA, CBAABC
        start, end = mid, mid + 1
        while start > -1 and end < len(string):
            if string[start] == string[end]:
                palindrome[start].append(end)
                start -= 1 
                end += 1 
            else:
                break
    
    # print(f"palindrome: {palindrome}")

    for end in palindrome[0]:
        dp[end] = 1
    for start in range(1, len(string)):
        for end in palindrome[start]:
            dp[end] = min(dp[end], dp[start - 1] + 1)

    return dp[len(string) -1]

if __name__=="__main__":
    print(solve())