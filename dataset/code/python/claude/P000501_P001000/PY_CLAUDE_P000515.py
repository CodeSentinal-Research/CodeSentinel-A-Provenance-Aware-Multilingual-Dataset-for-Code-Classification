
s=input().strip();depth=0;mx=0
for c in s:
    if c=='(': depth+=1;mx=max(mx,depth)
    elif c==')': depth-=1
print(mx)
