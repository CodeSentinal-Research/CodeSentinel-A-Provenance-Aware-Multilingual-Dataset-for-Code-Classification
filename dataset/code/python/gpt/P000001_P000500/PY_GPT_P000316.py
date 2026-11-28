# problem title : Isomorphic Strings
# Isomorphic strings require a one-to-one mapping in both directions.
a=input(); b=input(); m={}; rev={}; ok=len(a)==len(b)
for x,y in zip(a,b):
    if (x in m and m[x]!=y) or (y in rev and rev[y]!=x):ok=False;break
    m[x]=y;rev[y]=x
print("Yes" if ok else "No")
