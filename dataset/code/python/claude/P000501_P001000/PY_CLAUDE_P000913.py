
n,r,p=int(input()),int(input()),int(input())
def fact_mod(x,mod):
    res=1
    for i in range(2,x+1): res=res*i%mod
    return res
if r>n: print(0)
else:
    num=fact_mod(n,p)
    den=fact_mod(r,p)*fact_mod(n-r,p)%p
    print(num*pow(den,p-2,p)%p)
