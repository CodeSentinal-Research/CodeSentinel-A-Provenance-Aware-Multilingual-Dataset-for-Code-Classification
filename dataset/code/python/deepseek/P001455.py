def longest_duplicate_substring(s):
    n = len(s)
    dp = [0] * n
    for i in range(1, n):
        m = dp[i-1]
        while m > 0 and s[i] == s[i-m]:
            m -= 1
        dp[i+1] = m + 1 if s[i] == s[i-m] else dp[i]

    max_len = max(dp)
    res = s[dp.index(max_len):max_len+1]
    return res

def main():
    s = input()
    print(longest_duplicate_substring(s))

if __name__ == "__main__":
    main()