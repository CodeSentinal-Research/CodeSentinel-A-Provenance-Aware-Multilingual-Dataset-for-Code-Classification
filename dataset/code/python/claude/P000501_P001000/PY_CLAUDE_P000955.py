
a,m=int(input()),int(input())
def ext_gcd(a,b):
    if b==0: return 1,0
    x,y=ext_gcd(b,a%b)
    return y,x-(a//b)*y
x,_=ext_gcd(a,m)
print(x%m)
