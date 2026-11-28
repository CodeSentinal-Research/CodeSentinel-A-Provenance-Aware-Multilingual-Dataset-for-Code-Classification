
n=int(input());a=list(map(int,input().split()))
root=a[0]
print(sum(1 for v in a[1:] if v>root))
