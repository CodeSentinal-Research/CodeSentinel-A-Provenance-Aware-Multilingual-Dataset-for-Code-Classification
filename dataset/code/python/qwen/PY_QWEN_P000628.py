import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    text = []
    cur = 0
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "addText":
            t = d[idx]; idx += 1
            text.insert(cur, t)
            cur += len(t)
        elif op == "deleteText":
            k = int(d[idx]); idx += 1
            del text[max(0, cur-k):cur]
            cur = max(0, cur-k)
        elif op == "cursorLeft":
            k = int(d[idx]); idx += 1
            cur = max(0, cur-k)
            print("".join(text)[max(0, cur-10):cur])
        elif op == "cursorRight":
            k = int(d[idx]); idx += 1
            cur = min(len("".join(text)), cur+k)
            print("".join(text)[max(0, cur-10):cur])
solve()
