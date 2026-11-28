
dividend,divisor=int(input()),int(input())
sign=-1 if (dividend<0)^(divisor<0) else 1
a,b=abs(dividend),abs(divisor)
q=0
for i in range(31,-1,-1):
    if a>=(b<<i): a-=(b<<i);q+=(1<<i)
q=sign*q
INT_MAX,INT_MIN=2**31-1,-2**31
print(max(INT_MIN,min(INT_MAX,q)))
