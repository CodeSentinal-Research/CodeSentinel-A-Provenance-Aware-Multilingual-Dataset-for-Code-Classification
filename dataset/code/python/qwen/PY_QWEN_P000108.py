n = int(input())
arr = list(map(int, input().split()))
if arr == sorted(arr, reverse=True):
    print("Sorted")
else:
    print("Not Sorted")
