n = int(input())
arr = list(map(int, input().split()))
sorted_arr = sorted(arr)
pos = {val: i for i, val in enumerate(arr)}
swaps = 0
visited = [False] * n
for i in range(n):
    if visited[i] or arr[i] == sorted_arr[i]:
        continue
    cycle_size = 0
    j = i
    while not visited[j]:
        visited[j] = True
        j = pos[sorted_arr[j]]
        cycle_size += 1
    if cycle_size > 0:
        swaps += (cycle_size - 1)
print(swaps)
