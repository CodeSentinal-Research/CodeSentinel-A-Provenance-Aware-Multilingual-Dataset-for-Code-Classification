n = int(input())
arr = list(map(int, input().split()))
dep = list(map(int, input().split()))
arr.sort()
dep.sort()
i = j = 0
platforms = 0
max_plat = 0
while i < n and j < n:
    if arr[i] <= dep[j]:
        platforms += 1
        max_plat = max(max_plat, platforms)
        i += 1
    else:
        platforms -= 1
        j += 1
print(max_plat)
