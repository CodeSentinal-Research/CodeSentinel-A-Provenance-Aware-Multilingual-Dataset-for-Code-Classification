
q=int(input())
removed=set();nxt=1
for _ in range(q):
    parts=input().split()
    if parts[0]=='pop':
        while nxt in removed: nxt+=1
        print(nxt);removed.add(nxt);nxt+=1
    else:
        v=int(parts[1])
        if v in removed: removed.remove(v)
