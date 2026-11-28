# problem title : Find Union of Two Unsorted Arrays
# Set union removes duplicates from both unsorted arrays.
m, n = map(int, input().split()); first = set(map(int, input().split())); second = set(map(int, input().split()))
print(*sorted(first | second))
