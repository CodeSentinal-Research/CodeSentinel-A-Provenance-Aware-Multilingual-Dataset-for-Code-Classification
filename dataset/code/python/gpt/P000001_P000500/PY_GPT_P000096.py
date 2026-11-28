# problem title : Check Spy Number
# A spy number has equal digit sum and digit product.
n = int(input())
digits = [int(d) for d in str(n)]
product = 1
for d in digits: product *= d
print("Spy" if sum(digits) == product else "Not Spy")
