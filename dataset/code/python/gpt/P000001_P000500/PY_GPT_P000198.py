# problem title : Check if Array Contains Contiguous Integers
# Remove duplicates conceptually, then a contiguous integer set must span exactly its size.
n = int(input()); a = list(map(int, input().split()))[:n]
unique = set(a)
print("Yes" if max(unique) - min(unique) + 1 == len(unique) else "No")
