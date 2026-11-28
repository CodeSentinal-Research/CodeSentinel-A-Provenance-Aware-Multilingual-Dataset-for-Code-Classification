
s=input().strip();stk=[]
import re
pattern=re.compile(r'<(/?)([A-Z]{1,9})>')
i=0;valid=True
while i<len(s):
    if s[i]=='<':
        j=s.find('>',i)
        if j==-1: valid=False;break
        tag=s[i:j+1];m=pattern.fullmatch(tag)
        if not m: valid=False;break
        if m.group(1):
            if not stk or stk[-1]!=m.group(2): valid=False;break
            stk.pop()
        else: stk.append(m.group(2))
        i=j+1
    else: i+=1
print('true' if valid and not stk else 'false')
