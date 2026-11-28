# problem title : Find Smallest Element in Array
# The minimum array element is the required result.
n = int(input()); values = list(map(int, input().split()))
print(min(values[:n]))
