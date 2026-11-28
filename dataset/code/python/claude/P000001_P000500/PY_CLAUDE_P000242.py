
import bisect
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
print(sum(row.count(0) for row in A))
