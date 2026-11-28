
sz=int(input());a=list(map(int,input().split()));n=int(input())
idx=sz-n
a.pop(idx)
print(*a if a else [''])
