
n=int(input())
count=0
for i in range(1,10**n):
    s=str(i)
    if len(set(s))==len(s): count+=1
print(count)
