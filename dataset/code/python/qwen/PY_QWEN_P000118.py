n = int(input())
arr = list(map(int, input().split()))
non_zero = [x for x in arr if x != 0]
zeros = [0] * (n - len(non_zero))
print(" ".join(map(str, non_zero + zeros)))
