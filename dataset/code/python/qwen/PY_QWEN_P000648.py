import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    doc = []
    undo = []
    redo = []
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "type":
            t = d[idx]; idx += 1
            doc.append(t)
            undo.append(t)
            redo.clear()
        elif op == "undo":
            if undo:
                redo.append(undo.pop())
                doc.pop()
        elif op == "redo":
            if redo:
                t = redo.pop()
                doc.append(t)
                undo.append(t)
        elif op == "print":
            print("".join(doc))
solve()
