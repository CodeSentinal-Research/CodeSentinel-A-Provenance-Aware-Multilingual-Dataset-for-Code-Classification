
s=input().strip();k=int(input())
size=0
for c in s: size=size*int(c) if c.isdigit() else size+1
for c in reversed(s):
    k%=size
    if k==0 and c.isalpha(): print(c);break
    size=size//int(c) if c.isdigit() else size-1
