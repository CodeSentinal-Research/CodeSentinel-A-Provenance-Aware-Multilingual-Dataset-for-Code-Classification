# problem title : Reverse a Number
n = int(input())
s = str(abs(n))[::-1]
print((-1 if n < 0 else 1) * int(s))
