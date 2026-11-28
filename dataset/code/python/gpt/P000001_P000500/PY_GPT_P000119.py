# problem title : Separate Even and Odd Numbers
# Stable partition: collect evens first and odds second.
n = int(input()); a = list(map(int, input().split()))[:n]
result = [x for x in a if x % 2 == 0] + [x for x in a if x % 2 != 0]
print(*result)
