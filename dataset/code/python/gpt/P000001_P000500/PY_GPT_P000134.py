# problem title : Sort Array by Parity
# Stable parity partition places every even number before every odd number.
n = int(input()); a = list(map(int, input().split()))[:n]
a.sort(key=lambda x: x % 2)
print(*a)
