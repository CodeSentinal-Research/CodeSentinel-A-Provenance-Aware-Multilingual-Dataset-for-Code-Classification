n = int(input())
arr = list(map(int, input().split()))
if len(arr) != len(set(arr)):
    print("Yes")
else:
    print("No")
