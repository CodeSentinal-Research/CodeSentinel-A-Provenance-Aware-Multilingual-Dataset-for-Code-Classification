from typing import List

def dynamic_connectivity(n: int, queries: List[List[int]]) -> List[str]:
    parent = list(range(n))
    def find(i):
        if parent[i] == i: return i
        parent[i] = find(parent[i])
        return parent[i]

    res = []
    for type_, u, v in queries:
        if type_ == 1:
            ru, rv = find(u), find(v)
            if ru != rv:
                parent[ru] = rv
        else:
            res.append("YES" if find(u) == find(v) else "NO")
    return res

if __name__ == '__main__':
    import sys
    lines = sys.stdin.read().splitlines()
    if lines:
        n, q = map(int, lines[0].split())
        queries = [list(map(int, line.split())) for line in lines[1:q+1]]
        out = dynamic_connectivity(n, queries)
        for line in out:
            print(line)