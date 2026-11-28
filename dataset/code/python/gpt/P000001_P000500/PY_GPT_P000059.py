# problem title : Find Product of Digits
# Multiply every decimal digit; zero makes the whole product zero.
n = int(input())
product = 1
for digit in str(n):
    product *= int(digit)
print(product)
