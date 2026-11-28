s = input().strip()
n = int(input())
words = [input().strip() for _ in range(n)]
bold = [False] * len(s)
for i in range(len(s)):
    for w in words:
        if s.startswith(w, i):
            for j in range(i, i + len(w)):
                bold[j] = True
res = []
for i in range(len(s)):
    if bold[i] and (i == 0 or not bold[i-1]):
        res.append("<b>")
    res.append(s[i])
    if bold[i] and (i == len(s) - 1 or not bold[i+1]):
        res.append("</b>")
print("".join(res))
