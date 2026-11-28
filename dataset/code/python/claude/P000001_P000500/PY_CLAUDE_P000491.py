
m=int(input());target=list(map(int,input().split()));n=int(input())
ops=[];cur=1
for t in target:
    while cur<t: ops.extend(['Push','Pop']);cur+=1
    ops.append('Push');cur+=1
print(*ops,sep='\n')
