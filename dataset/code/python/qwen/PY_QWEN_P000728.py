import sys
def solve():
    s = sys.stdin.read().split()[0]
    def valid(st):
        c = 0
        for ch in st:
            if ch == '(': c += 1
            elif ch == ')': c -= 1
            if c < 0: return False
        return c == 0
    q = {s}
    while True:
        v = [x for x in q if valid(x)]
        if v:
            for x in sorted(set(v)): print(x)
            break
        nq = set()
        for item in q:
            for i in range(len(item)):
                if item[i] in "()": nq.add(item[:i] + item[i+1:])
        q = nq
solve()
