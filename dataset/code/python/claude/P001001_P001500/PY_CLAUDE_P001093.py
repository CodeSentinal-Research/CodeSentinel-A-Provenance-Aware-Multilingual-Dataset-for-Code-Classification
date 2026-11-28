
n,m1,m2=map(int,input().split())
edges1=[tuple(map(int,input().split())) for _ in range(m1)]
edges2=[tuple(map(int,input().split())) for _ in range(m2)]
from collections import Counter
deg1=Counter();deg2=Counter()
for u,v in edges1: deg1[u]+=1;deg1[v]+=1
for u,v in edges2: deg2[u]+=1;deg2[v]+=1
print('true' if sorted(deg1.values())==sorted(deg2.values()) and m1==m2 else 'false')
