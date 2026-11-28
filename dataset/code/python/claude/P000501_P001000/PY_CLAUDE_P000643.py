
n=int(input());a=list(map(int,input().split()));v=int(input())
if v in a: a.remove(v)
print(*a)
