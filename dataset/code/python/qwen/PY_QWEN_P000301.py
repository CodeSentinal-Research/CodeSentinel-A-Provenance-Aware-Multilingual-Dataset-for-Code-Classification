s = input().strip()
res = []
def dfs(idx, path, dots):
    if dots == 3:
        if idx < len(s) and int(s[idx:]) <= 255 and (s[idx] != '0' or idx == len(s) - 1):
            res.append(path + s[idx:])
        return
    for i in range(idx + 1, min(idx + 4, len(s))):
        seg = s[idx:i]
        if len(seg) > 1 and seg[0] == '0':
            break
        if int(seg) <= 255:
            dfs(i, path + seg + '.', dots + 1)
dfs(0, "", 0)
for ip in res:
    print(ip)
