def children_indices(i: int, n: int):
    l = 2 * i + 1 if 2 * i + 1 < n else -1
    r = 2 * i + 2 if 2 * i + 2 < n else -1
    return l, r

if __name__ == '__main__':
    i, n = map(int, input().split())
    l, r = children_indices(i, n)
    print(f"{l} {r}")