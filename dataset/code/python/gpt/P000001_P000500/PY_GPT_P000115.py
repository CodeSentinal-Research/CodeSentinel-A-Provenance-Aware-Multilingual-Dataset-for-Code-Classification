# problem title : Rotate Array Right by K Positions
# A right rotation by K is the same as moving the final K values forward.
n, k = map(int, input().split()); a = list(map(int, input().split()))[:n]
k %= n
print(*(a[-k:] + a[:-k] if k else a))
