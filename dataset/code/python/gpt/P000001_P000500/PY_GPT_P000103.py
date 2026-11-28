# problem title : Sum of Array Elements
# Accumulate all array values to obtain the total sum.
n = int(input()); values = list(map(int, input().split()))
total = 0
for value in values[:n]: total += value
print(total)
