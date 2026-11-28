import sys
def solve():
    word = sys.stdin.read().split()[0]
    res = []
    def rec(idx, curr):
        if idx == len(word):
            if curr: res.append(curr)
            return
        rec(idx + 1, curr + word[idx])
        cnt = 0
        while idx < len(word) and word[idx].isalpha():
            cnt += 1
            idx += 1
        if cnt > 0: res.append(curr + str(cnt))
        rec(idx, curr + str(cnt) if cnt > 0 else curr)
    rec(0, "")
    for x in sorted(res): print(x)
solve()
