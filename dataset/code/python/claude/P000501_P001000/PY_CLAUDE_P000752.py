
n=int(input());a=list(map(int,input().split()));t=int(input())
def bt(i,cur,rem):
    if rem==0: print(*cur);return True
    if i==n: return False
    if a[i]<=rem and bt(i+1,cur+[a[i]],rem-a[i]): return True
    return bt(i+1,cur,rem)
if not bt(0,[],t): print(-1)
