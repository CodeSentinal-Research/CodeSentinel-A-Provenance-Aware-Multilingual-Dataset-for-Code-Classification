
line1=input().strip();line2=input().strip()
broken=set(line2)
count=0
for w in line1.split():
    if not any(c in broken for c in w): count+=1
print(count)
