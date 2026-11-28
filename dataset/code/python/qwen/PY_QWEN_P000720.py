import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    num, target = d[0], int(d[1])
    res = []
    def rec(idx, path, curr_val, last_val):
        if idx == len(num):
            if curr_val == target: res.append(path)
            return
        val = 0
        for i in range(idx, len(num)):
            val = val * 10 + int(num[i])
            if i == 0:
                rec(i + 1, num[idx:i+1], val, val)
            else:
                rec(i + 1, path + "+" + num[idx:i+1], curr_val + val, val)
                rec(i + 1, path + "-" + num[idx:i+1], curr_val - val, val)
                rec(i + 1, path + "*" + num[idx:i+1], last_val * val, val)
    rec(0, "", 0, 0)
    for x in res: print(x)
solve()
