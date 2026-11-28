
n=int(input())
from math import isqrt
def is_prime(x):
    if x<2: return False
    return all(x%i!=0 for i in range(2,isqrt(x)+1))
n+=1
while not is_prime(n): n+=1
print(n)
