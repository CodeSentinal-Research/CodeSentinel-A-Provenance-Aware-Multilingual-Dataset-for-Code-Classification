# problem title : Word Pattern
# Enforce a bijection between pattern symbols and words.
p=input(); w=input().split(); a={};b={};ok=len(p)==len(w)
for x,y in zip(p,w):
    if (x in a and a[x]!=y) or (y in b and b[y]!=x):ok=False;break
    a[x]=y;b[y]=x
print("Yes" if ok else "No")
