import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    wins = {}
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "newWindow":
            wid, url = int(d[idx]), d[idx+1]; idx += 2
            wins[wid] = ([url], 0)
        elif op == "closeWindow":
            wid = int(d[idx]); idx += 1
            if wid in wins: del wins[wid]
        elif op == "visit":
            wid, url = int(d[idx]), d[idx+1]; idx += 2
            if wid in wins:
                h, c = wins[wid]
                wins[wid] = (h[:c+1] + [url], c + 1)
        elif op == "back":
            wid, st = int(d[idx]), int(d[idx+1]); idx += 2
            if wid in wins:
                h, c = wins[wid]
                c = max(0, c - st)
                wins[wid] = (h, c)
                print(h[c])
        elif op == "forward":
            wid, st = int(d[idx]), int(d[idx+1]); idx += 2
            if wid in wins:
                h, c = wins[wid]
                c = min(len(h) - 1, c + st)
                wins[wid] = (h, c)
                print(h[c])
        elif op == "currentPage":
            wid = int(d[idx]); idx += 1
            if wid in wins: print(wins[wid][0][wins[wid][1]])
solve()
