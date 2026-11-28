s = input().strip()
def dfs(s):
    res = []
    for i, c in enumerate(s):
        if c in '+-*':
            left = dfs(s[:i])
            right = dfs(s[i+1:])
            for l in left:
                for r in right:
                    if c == '+': res.append(l + r)
                    elif c == '-': res.append(l - r)
                    elif c == '*': res.append(l * r)
    if not res:
        res.append(int(s))
    return res
for val in sorted(dfs(s)):
    print(val)
