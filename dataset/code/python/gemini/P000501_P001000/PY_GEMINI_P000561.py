import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        count = {}
        q = []
        res = []
        for c in s:
            count[c] = count.get(c, 0) + 1
            q.append(c)
            while q and count[q[0]] > 1:
                q.pop(0)
            res.append(q[0] if q else '#')
        print("".join(res))
if __name__ == '__main__':
    main()