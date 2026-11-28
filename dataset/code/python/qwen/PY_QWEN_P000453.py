n = int(input())
arr = list(map(int, input().split()))
ans = -1
for i in range(n):
    if arr[i] == i:
        ans = i
        break
print(ans)
