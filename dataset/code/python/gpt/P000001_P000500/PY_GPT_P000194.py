# problem title : Find Intersection of Two Unsorted Arrays
# Set intersection keeps only values shared by both arrays.
m, n = map(int, input().split()); left = set(map(int, input().split())); right = set(map(int, input().split()))
print(*sorted(left.intersection(right)))
