
s=input().strip()
def bt(i,prev,cnt):
    if i==len(s): return cnt>=3
    for j in range(i+1,len(s)+1):
        num=int(s[i:j])
        if prev is None or num==prev-1:
            if bt(j,num,cnt+1): return True
    return False
print('true' if bt(0,None,0) else 'false')
