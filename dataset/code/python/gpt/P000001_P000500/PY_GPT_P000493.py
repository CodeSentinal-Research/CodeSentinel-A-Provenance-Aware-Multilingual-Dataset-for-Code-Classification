# problem title : Remove K Digits
# A monotonic increasing stack removes larger preceding digits to minimize the number.
s=input();k=int(input());st=[]
for ch in s:
 while k and st and st[-1]>ch:st.pop();k-=1
 st.append(ch)
if k:st=st[:-k]
ans=''.join(st).lstrip('0')
print(ans or '0')
