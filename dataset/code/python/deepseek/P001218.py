def word_break():
    s = input()
    n = int(input())
    words = set(input() for _ in range(n))
    dp = [False] * (len(s) + 1)
    dp[0] = True
    for i in range(1, len(s) + 1):
        for j in range(i):
            if dp[j] and s[j:i] in words:
                dp[i] = True
                break
    print('YES' if dp[-1] else 'NO')

if __name__ == '__main__':
    word_break()