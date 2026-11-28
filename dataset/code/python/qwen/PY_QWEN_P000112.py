n = int(input())
arr = list(map(int, input().split()))
uniq = sorted(list(set(arr)))
if len(uniq) >= 2:
    print(uniq[1])
else:
    print(-1)
