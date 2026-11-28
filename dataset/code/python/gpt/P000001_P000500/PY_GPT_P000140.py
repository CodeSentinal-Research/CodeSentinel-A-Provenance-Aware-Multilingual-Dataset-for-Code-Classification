# problem title : Union of Two Arrays
# Union of sets automatically removes repeated values.
m, n = map(int, input().split()); a = set(map(int, input().split())); b = set(map(int, input().split()))
print(*sorted(a | b))
