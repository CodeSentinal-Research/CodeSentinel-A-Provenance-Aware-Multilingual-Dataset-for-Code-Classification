n, k, target = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(key=lambda x: (abs(x - target), x))
print(" ".join(map(str, sorted(arr[:k]))))
