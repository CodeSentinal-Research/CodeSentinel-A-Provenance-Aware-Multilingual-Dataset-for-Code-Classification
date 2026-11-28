
from collections import deque
start=input().strip();end=input().strip();n=int(input());bank=set(input().strip() for _ in range(n))
if end not in bank: print(-1);exit()
q=deque([(start,0)]);visited={start}
while q:
    gene,mut=q.popleft()
    for i in range(len(gene)):
        for c in 'ACGT':
            ng=gene[:i]+c+gene[i+1:]
            if ng==end: print(mut+1);exit()
            if ng in bank and ng not in visited: visited.add(ng);q.append((ng,mut+1))
print(-1)
