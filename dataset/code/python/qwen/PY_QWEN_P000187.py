n = int(input())
arr = list(map(int, input().split()))
seen = set(arr)
for i in range(1, n + 2):
    if i not in seen:
        print(i)
        break
