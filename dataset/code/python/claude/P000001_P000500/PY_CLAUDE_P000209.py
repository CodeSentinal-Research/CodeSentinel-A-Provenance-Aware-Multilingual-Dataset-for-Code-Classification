
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
for layer in range(n // 2):
    first, last = layer, n - 1 - layer
    for i in range(first, last):
        off = i - first
        top = A[first][i]
        A[first][i] = A[last-off][first]
        A[last-off][first] = A[last][last-off]
        A[last][last-off] = A[first+off][last]
        A[first+off][last] = top
for row in A:
    print(*row)
