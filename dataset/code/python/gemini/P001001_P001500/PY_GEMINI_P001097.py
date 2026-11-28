def simulate_dsu(n, operations):
    parent = list(range(n))
    def find(i):
        if parent[i] == i: return i
        parent[i] = find(parent[i])
        return parent[i]

    def union(i, j):
        ri, rj = find(i), find(j)
        if ri != rj:
            parent[ri] = rj

    res = []
    for op in operations:
        parts = op.split()
        if parts[0] == "UNION":
            union(int(parts[1]), int(parts[2]))
        elif parts[0] == "FIND":
            res.append(str(find(int(parts[1]))))
        elif parts[0] == "CONNECTED":
            res.append("YES" if find(int(parts[1])) == find(int(parts[2])) else "NO")
    return res

if __name__ == '__main__':
    import sys
    lines = sys.stdin.read().splitlines()
    if lines:
        n, q = map(int, lines[0].split())
        out = simulate_dsu(n, lines[1:q+1])
        for line in out:
            print(line)