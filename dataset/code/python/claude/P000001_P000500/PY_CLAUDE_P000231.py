
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
print(*sorted(x for row in A for x in row))
