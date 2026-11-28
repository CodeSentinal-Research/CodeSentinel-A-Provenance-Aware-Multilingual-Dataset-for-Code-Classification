
a,b=int(input()),int(input())
def ext_gcd(a,b):
    if b==0: return a,1,0
    g,x,y=ext_gcd(b,a%b)
    return g,y,x-(a//b)*y
g,x,y=ext_gcd(a,b)
print(g,x,y)
