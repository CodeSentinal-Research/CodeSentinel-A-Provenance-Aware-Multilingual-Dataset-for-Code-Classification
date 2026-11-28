
n=int(input());a=list(map(int,input().split()))
last=a[-1];lo=[v for v in a[:-1] if v<=last];hi=[v for v in a[:-1] if v>last]
print(*lo,last,*hi)
