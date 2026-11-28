# problem title : Cyclically Rotate Array by One
# Move the last element to the front for a one-step right rotation.
n = int(input()); a = list(map(int, input().split()))[:n]
print(*(a[-1:] + a[:-1]))
