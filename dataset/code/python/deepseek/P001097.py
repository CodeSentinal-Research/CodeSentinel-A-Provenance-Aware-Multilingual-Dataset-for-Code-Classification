def union_find(n, operations):
    parent = list(range(n+1))
    rank = [0] * (n+1)

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            parent[rx] = ry
            rank[ry] += 1

    for operation in operations:
        op, x, y = operation
        if op == 1:
            union(x, y)
        else:
            print('YES' if find(x) == find(y) else 'NO')

def main():
    n, q = map(int, input().split())
    operations = [tuple(map(int, input().split())) for _ in range(q)]
    union_find(n, operations)

if __name__ == '__main__':
    main()