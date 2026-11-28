# problem title : Intersection of Two Arrays
# Sets provide unique intersection elements directly.
m, n = map(int, input().split()); a = set(map(int, input().split())); b = set(map(int, input().split()))
print(*sorted(a & b))
