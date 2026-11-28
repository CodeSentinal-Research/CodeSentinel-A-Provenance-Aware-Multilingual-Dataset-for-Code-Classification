import sys
def solve():
    digits = sys.stdin.read().split()[0]
    if not digits: print(""); return
    mapping = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
    res = []
    def rec(idx, path):
        if idx == len(digits):
            res.append("".join(path))
            return
        for c in mapping[digits[idx]]:
            path.append(c)
            rec(idx + 1, path)
            path.pop()
    rec(0, [])
    print(" ".join(res))
solve()
