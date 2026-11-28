
n=int(input());a=list(map(int,input().split()));t=int(input())
def bt(i,cur,rem):
    if rem==0: print(*cur);return
    if i==n: return
    if a[i]<=rem: bt(i+1,cur+[a[i]],rem-a[i])
    bt(i+1,cur,rem)
bt(0,[],t)
