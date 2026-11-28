
n=int(input());a=list(map(int,input().split()))
half=n//2;total=sum(a);best=[float('inf')];part=[[]]
def bt(i,cur,cur_sum,cnt):
    if cnt==half:
        other_sum=total-cur_sum
        diff=abs(cur_sum-other_sum)
        if diff<best[0]: best[0]=diff;part[0]=cur[:]
        return
    if i==n: return
    if n-i >= half-cnt:
        cur.append(a[i]);bt(i+1,cur,cur_sum+a[i],cnt+1);cur.pop()
    bt(i+1,cur,cur_sum,cnt)
bt(0,[],0,0)
print(best[0])
other=[x for x in a if x not in part[0]]
print(*sorted(part[0]));print(*sorted(other))
