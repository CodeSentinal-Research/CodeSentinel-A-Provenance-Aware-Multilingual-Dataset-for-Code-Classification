# problem title : Build Array With Stack Operations
# Simulate the target construction: push values from 1 upward and pop when the next target value is reached.
m=int(input());target=list(map(int,input().split()));n=int(input());out=[];i=0
for x in range(1,n+1):
 out.append('Push')
 if i<len(target) and target[i]==x:i+=1
 else:out.append('Pop')
 if i==len(target):break
print(*out)
