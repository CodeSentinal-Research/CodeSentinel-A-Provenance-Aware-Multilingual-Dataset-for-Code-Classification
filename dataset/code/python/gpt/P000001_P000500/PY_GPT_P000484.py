# problem title : Decode String
# Decode nested repetition with stacks for counts and partial strings.
s=input();counts=[];parts=[''];num=0
for ch in s:
 if ch.isdigit():num=num*10+int(ch)
 elif ch=='[':counts.append(num);parts.append('');num=0
 elif ch==']':parts[-2]+=parts.pop()*counts.pop()
 else:parts[-1]+=ch
print(parts[0])
