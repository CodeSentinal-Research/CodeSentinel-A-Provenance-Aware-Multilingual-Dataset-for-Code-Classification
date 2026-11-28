# problem title : Segregate 0s and 1s
# Stable binary partition puts every zero before every one.
n = int(input()); a = list(map(int, input().split()))[:n]
print(*([0] * a.count(0) + [1] * a.count(1)))
