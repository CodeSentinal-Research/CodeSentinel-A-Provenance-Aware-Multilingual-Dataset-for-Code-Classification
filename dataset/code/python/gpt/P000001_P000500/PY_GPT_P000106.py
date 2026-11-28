# problem title : Reverse an Array
# Reverse the sequence while preserving every element.
n = int(input()); values = list(map(int, input().split()))[:n]
values.reverse()
print(*values)
