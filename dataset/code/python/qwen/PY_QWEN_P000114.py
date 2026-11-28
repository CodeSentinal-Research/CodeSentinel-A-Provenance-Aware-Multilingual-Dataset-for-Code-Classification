n, k = map(int, input().split())
arr = list(map(int, input().split()))
k = k % n
print(" ".join(map(str, arr[k:] + arr[:k])))
