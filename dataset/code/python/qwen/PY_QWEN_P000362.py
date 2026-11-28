n = int(input())
arr = list(map(int, input().split()))
x = int(input())
for i, val in enumerate(arr):
    if val > x:
        print(i)
        break
else:
    print(-1)
