import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    rooms = []
    idx = 1
    for _ in range(n):
        sz = int(input_data[idx]); idx += 1
        rooms.append(list(map(int, input_data[idx:idx+sz])))
        idx += sz
    vis = {0}
    q = [0]
    while q:
        nxt = []
        for r in q:
            for k in rooms[r]:
                if k not in vis:
                    vis.add(k)
                    nxt.append(k)
        q = nxt
    print("true" if len(vis) == n else "false")
solve()
