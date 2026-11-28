# problem title : Find HCF of Two Numbers
# Euclid's algorithm gives the highest common factor efficiently.
a, b = map(int, input().split())
while b:
    a, b = b, a % b
print(a)
