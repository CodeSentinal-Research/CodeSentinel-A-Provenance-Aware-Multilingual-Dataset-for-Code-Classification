
n = int(input())
pairs = [tuple(map(int, input().split())) for _ in range(n)]
pairs.sort(key=lambda x: x[1])
count, end = 1, pairs[0][1]
for a, b in pairs[1:]:
    if a > end: count += 1; end = b
print(count)
