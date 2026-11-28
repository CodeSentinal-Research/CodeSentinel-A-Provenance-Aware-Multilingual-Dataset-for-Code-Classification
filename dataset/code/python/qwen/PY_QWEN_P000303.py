s = input().strip()
n = int(input())
words = set(input().strip() for _ in range(n))
res = []
def dfs(idx, path):
    if idx == len(s):
        res.append(" ".join(path))
        return
    for i in range(idx + 1, len(s) + 1):
        if s[idx:i] in words:
            path.append(s[idx:i])
            dfs(i, path)
            path.pop()
dfs(0, [])
for sentence in res:
    print(sentence)
