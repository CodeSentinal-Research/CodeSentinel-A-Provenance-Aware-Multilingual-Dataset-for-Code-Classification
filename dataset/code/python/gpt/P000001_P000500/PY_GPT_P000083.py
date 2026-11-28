# problem title : Find Largest Among Three Numbers Using Nested If
# Use nested decisions rather than max(), matching the requested approach.
a, b, c = map(int, input().split())
if a >= b:
    largest = a if a >= c else c
else:
    largest = b if b >= c else c
print(largest)
