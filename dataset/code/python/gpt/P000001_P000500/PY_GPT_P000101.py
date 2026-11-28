# problem title : Find Largest Element in Array
# Scan once while retaining the largest value seen.
n = int(input()); values = list(map(int, input().split()))
print(max(values[:n]))
