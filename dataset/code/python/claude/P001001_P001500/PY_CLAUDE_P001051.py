
import heapq
n,q=map(int,input().split());a=list(map(int,input().split()))
for _ in range(q):
    line=input().split()
    op=line[0]
    if op=='insert': a.append(int(line[1]));heapq.heapify(a)
    elif op=='delete': i=int(line[1]);a[i]=a[-1];a.pop();heapq.heapify(a)
    print(*a)
