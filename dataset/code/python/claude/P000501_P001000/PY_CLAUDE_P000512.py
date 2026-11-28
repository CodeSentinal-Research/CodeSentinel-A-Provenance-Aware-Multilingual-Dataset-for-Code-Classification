
s=input().strip();cnt=0;opens=0
for c in s:
    if c=='[': opens+=1
    else:
        if opens>0: opens-=1
        else: cnt+=1
print((cnt+1)//2)
