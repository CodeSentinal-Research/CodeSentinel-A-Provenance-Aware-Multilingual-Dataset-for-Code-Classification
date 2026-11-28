# problem title : Count Frequency of an Element
# Count target matches directly in the input array.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
print(sum(value == target for value in a))
