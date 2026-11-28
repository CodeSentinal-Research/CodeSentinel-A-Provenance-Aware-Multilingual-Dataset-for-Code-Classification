
import heapq
n=int(input());a=list(map(int,input().split()));k=int(input())
print(heapq.nlargest(k,a)[-1])
