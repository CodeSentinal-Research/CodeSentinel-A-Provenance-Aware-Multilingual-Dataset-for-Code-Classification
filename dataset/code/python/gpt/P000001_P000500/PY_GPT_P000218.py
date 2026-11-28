# problem title : Majority Element II
# Boyer-Moore keeps candidates that can occur more than floor(N/3) times.
n=int(input()); a=list(map(int,input().split())); c1=c2=0; x=y=None
for v in a:
    if v==x:c1+=1
    elif v==y:c2+=1
    elif c1==0:x=v;c1=1
    elif c2==0:y=v;c2=1
    else:c1-=1;c2-=1
out=[v for v in (x,y) if v is not None and a.count(v)>n//3]; print(*sorted(set(out)))
