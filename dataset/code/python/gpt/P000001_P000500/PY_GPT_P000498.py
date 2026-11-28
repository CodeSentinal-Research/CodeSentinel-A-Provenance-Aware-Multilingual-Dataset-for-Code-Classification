# problem title : Basic Calculator
# Parse the expression with a stack so nested parentheses and signed terms are handled left to right.
s=input();stack=[];num=0;sign=1;total=0;i=0
while i<len(s):
 ch=s[i]
 if ch.isdigit():num=num*10+int(ch)
 elif ch in '+-':total+=sign*num;num=0;sign=1 if ch=='+' else -1
 elif ch=='(':stack.append((total,sign));total=0;sign=1
 elif ch==')':total+=sign*num;num=0;prev,op=stack.pop();total=prev+op*total
 i+=1
print(total+sign*num)
