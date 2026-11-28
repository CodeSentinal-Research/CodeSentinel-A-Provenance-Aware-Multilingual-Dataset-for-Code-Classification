n = int(input())
arr = list(map(int, input().split()))
uniq = sorted(list(set(arr)), reverse=True)
if len(uniq) >= 3:
    print(uniq[2])
else:
    print(uniq[0])
