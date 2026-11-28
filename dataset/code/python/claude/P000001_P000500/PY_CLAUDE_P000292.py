
s=input();stack=[['',0]];i=0
while i<len(s):
    if s[i].isdigit():
        num=0
        while i<len(s) and s[i].isdigit(): num=num*10+int(s[i]);i+=1
        stack.append([stack[-1][0],num])
    elif s[i]=='[':
        stack[-1][0]='';i+=1
    elif s[i]==']':
        seg,k=stack.pop();stack[-1][0]+=seg*k;i+=1
    else: stack[-1][0]+=s[i];i+=1
print(stack[0][0])
