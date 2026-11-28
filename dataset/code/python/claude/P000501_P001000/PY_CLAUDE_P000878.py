
n=int(input());a=list(map(int,input().split()))
cur=set([0]);res=set([0])
for v in a:
    cur={x|v for x in cur}|{v}
    res|=cur
print(len(res))
