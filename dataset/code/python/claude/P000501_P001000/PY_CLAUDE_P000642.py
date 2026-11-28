
n=int(input());a=list(map(int,input().split()));pos=int(input());v=int(input())
a.insert(pos-1,v)
print(*a)
