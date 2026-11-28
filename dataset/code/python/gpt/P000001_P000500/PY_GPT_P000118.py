# problem title : Move All Zeroes to End
# Preserve nonzero order, then append the required number of zeroes.
n = int(input()); a = list(map(int, input().split()))[:n]
nonzero = [x for x in a if x != 0]
print(*(nonzero + [0] * (n - len(nonzero))))
