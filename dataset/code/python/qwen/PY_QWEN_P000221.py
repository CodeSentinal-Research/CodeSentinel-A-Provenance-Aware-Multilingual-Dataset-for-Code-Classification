n = int(input())
pairs = [tuple(map(int, input().split())) for _ in range(n)]
pairs.sort(key=lambda x: x[1])
max_len = 1
curr_end = pairs[0][1]
for i in range(1, n):
    if pairs[i][0] > curr_end:
        max_len += 1
        curr_end = pairs[i][1]
print(max_len)
