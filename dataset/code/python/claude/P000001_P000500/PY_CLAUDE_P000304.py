
path=input().strip()
parts=path.split('/')
stack=[]
for p in parts:
    if p=='..' : 
        if stack: stack.pop()
    elif p and p!='.':
        stack.append(p)
print('/'+'/'.join(stack))
