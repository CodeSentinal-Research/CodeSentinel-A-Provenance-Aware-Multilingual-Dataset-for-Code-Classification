

n=int(input());a=list(map(int,input().split()))
evens=[v for v in a if v%2==0];odds=[v for v in a if v%2!=0]
print(*evens,*odds)
