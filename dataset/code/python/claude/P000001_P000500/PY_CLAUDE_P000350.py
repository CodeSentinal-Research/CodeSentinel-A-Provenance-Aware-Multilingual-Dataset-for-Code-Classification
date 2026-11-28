
s,k=input().split();k=int(k);stack=[]
for c in s:
    if stack and stack[-1][0]==c: stack[-1][1]+=1
    else: stack.append([c,1])
    if stack[-1][1]==k: stack.pop()
print(''.join(c*n for c,n in stack))
