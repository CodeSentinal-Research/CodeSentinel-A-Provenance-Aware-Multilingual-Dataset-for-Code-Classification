
source=input().strip();target=input().strip()
count=0;j=0
while j<len(target):
    matched=False
    for c in source:
        if j<len(target) and c==target[j]: j+=1;matched=True
    if not matched: print(-1);exit()
    count+=1
print(count)
