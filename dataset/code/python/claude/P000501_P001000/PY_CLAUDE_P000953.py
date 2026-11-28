
a,n=int(input()),int(input())
def phi(n):
    res=n;p=2;m=n
    while p*p<=m:
        if m%p==0:
            while m%p==0: m//=p
            res-=res//p
        p+=1
    if m>1: res-=res//m
    return res
print(pow(a,phi(n),n))
