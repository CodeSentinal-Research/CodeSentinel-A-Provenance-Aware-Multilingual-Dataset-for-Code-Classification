
n=int(input());a=list(map(int,input().split()));t=int(input())
count=[0]
def bt(i,rem):
    if rem==0: count[0]+=1;return
    if i==n: return
    if a[i]<=rem: bt(i+1,rem-a[i])
    bt(i+1,rem)
bt(0,t);print(count[0])
