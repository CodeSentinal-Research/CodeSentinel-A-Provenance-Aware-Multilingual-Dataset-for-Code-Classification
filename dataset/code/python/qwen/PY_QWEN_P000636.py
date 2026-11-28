import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    tabs = ["home"]
    cur = 0
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "open": tabs.insert(cur+1, d[idx]); idx += 1; cur += 1
        elif op == "close": tabs.pop(cur); cur = max(0, cur-1)
        elif op == "switch": cur = int(d[idx]); idx += 1
        elif op == "current": print(tabs[cur])
solve()
