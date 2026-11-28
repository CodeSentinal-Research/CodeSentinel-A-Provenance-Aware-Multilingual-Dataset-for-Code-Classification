s = input().strip()
n = int(input())
words = set(input().strip() for _ in range(n))
dp = [False] * (len(s) + 1)
dp[0] = True
for i in range(1, len(s) + 1):
    for j in range(i):
        if dp[j] and s[j:i] in words:
            dp[i] = True
            break
print("Yes" if dp[-1] else "No")
