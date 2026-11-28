import math
n = input().strip()
s = sum(math.factorial(int(x)) for x in n)
if s == int(n):
    print("Strong")
else:
    print("Not Strong")
