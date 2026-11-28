import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    pl = []
    cur = -1
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "addSong": pl.append(d[idx]); idx += 1
        elif op == "removeSong":
            s = d[idx]; idx += 1
            if s in pl:
                if pl.index(s) <= cur: cur -= 1
                pl.remove(s)
        elif op == "playNext":
            if pl: cur = (cur + 1) % len(pl)
        elif op == "playPrevious":
            if pl: cur = (cur - 1) % len(pl)
        elif op == "currentSong":
            print(pl[cur] if pl and cur != -1 else "None")
solve()
