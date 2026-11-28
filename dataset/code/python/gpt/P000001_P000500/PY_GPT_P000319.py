# problem title : One Edit Distance
# Two strings are one edit apart if one insertion, deletion, or replacement fixes them.
a=input(); b=input()
if abs(len(a)-len(b))>1: print("No")
else:
    if len(a)>len(b):a,b=b,a
    i=j=diff=0
    while i<len(a) and j<len(b):
        if a[i]!=b[j]:
            diff+=1
            if len(a)==len(b):i+=1
        else:i+=1
        j+=1
    diff += j<len(b)
    print("Yes" if diff==1 else "No")
