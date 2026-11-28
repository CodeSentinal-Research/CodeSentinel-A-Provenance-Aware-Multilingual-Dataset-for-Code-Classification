
n=int(input());a=list(map(int,input().split()));x=int(input())
lo=[v for v in a if v<x];hi=[v for v in a if v>=x]
print(*(lo+hi))
