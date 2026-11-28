n = int(input())
arr = list(map(int, input().split()))
uniq = list(set(arr))
uniq.sort()
is_cont = True
for i in range(1, len(uniq)):
    if uniq[i] != uniq[i-1] + 1:
        is_cont = False
        break
if is_cont:
    print("Yes")
else:
    print("No")
