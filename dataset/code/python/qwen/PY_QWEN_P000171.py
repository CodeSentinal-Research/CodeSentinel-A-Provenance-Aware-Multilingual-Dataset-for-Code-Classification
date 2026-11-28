n = int(input())
arr = list(map(int, input().split()))
zeros = arr.count(0)
ones = n - zeros
print(" ".join(["0"] * zeros + ["1"] * ones))
