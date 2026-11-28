def count_palindromic_substrings(s):
    n = len(s)
    dp = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n-1, -1, -1):
        dp[i][i] = 1
        for j in range(i+1, n):
            if s[i] == s[j]:
                if j-i==1 or dp[i+1][j-1] == 1:
                    dp[i][j] = 1

    count = [0]*(n+1)
    for i in range(n):
        count[dp[i][i]] += 1

    res = 0
    for i in range(1, n+1):
        if dp[0][i-1] == 1:
            res += count[i]

    return res

def main():
    s = input()
    print(count_palindromic_substrings(s))

if __name__ == "__main__":
    main()