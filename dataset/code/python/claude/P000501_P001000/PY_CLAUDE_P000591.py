
n=int(input());a=list(map(int,input().split()))
m=int(input());b=list(map(int,input().split()))
sa=set(a);inter=[v for v in b if v in sa]
print(inter[0] if inter else 'null')
