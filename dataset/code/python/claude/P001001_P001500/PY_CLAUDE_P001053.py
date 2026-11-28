
import heapq
q=int(input());h=[]
for _ in range(q):
    parts=input().split()
    if parts[0]=='push': heapq.heappush(h,int(parts[1]));print('ok')
    elif parts[0]=='pop': print(heapq.heappop(h) if h else -1)
    elif parts[0]=='top': print(h[0] if h else -1)
    elif parts[0]=='size': print(len(h))
