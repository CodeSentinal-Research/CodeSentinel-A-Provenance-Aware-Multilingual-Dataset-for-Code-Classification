# problem title : Check Strong Number
# A strong number equals the sum of factorials of its digits.
import math
n = int(input())
total = sum(math.factorial(int(d)) for d in str(n))
print("Strong" if total == n else "Not Strong")
