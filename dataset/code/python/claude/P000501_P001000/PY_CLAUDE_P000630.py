

sz=int(input());a=list(map(int,input().split()));k=int(input())
print(a[sz-k] if 1<=k<=sz else -1)
