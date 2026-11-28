
import heapq
n=int(input());a=list(map(int,input().split()));i=int(input())
heapq.heapify(a)
a[i]=a[-1];a.pop()
heapq.heapify(a)
print(*a)
