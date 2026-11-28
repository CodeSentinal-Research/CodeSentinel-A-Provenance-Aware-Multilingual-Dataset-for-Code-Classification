# problem title : Segregate Even and Odd
# Preserve each parity group while placing evens before odds.
n = int(input()); a = list(map(int, input().split()))[:n]
left = [x for x in a if x % 2 == 0]; right = [x for x in a if x % 2]
print(*(left + right))
