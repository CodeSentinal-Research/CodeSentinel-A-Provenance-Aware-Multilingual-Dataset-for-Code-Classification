n, k = map(int, input().split())
arr = list(map(int, input().split()))
k = k % n
if k > 0:
    print(" ".join(map(str, arr[-k:] + arr[:-k])))
else:
    print(" ".join(map(str, arr)))
