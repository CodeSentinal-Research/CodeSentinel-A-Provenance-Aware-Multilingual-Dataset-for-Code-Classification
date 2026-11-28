
n=int(input());a=list(map(int,input().split()));x=int(input());y=int(input())
if x in a and y in a:
    i,j=a.index(x),a.index(y);a[i],a[j]=a[j],a[i]
print(*a)
