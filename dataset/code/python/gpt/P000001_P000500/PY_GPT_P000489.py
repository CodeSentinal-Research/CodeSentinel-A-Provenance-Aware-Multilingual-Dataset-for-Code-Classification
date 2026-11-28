# problem title : Min Stack
# Store (value, minimum-so-far) pairs so getMin is constant time.
st=[];out=[]
for _ in range(int(input())):
 p=input().split();op=p[0]
 if op=='push':
  x=int(p[1]);st.append((x,min(x,st[-1][1]) if st else x))
 elif op=='pop':
  if st:st.pop()
 elif op=='top':out.append(str(st[-1][0]) if st else '-1')
 elif op in ('getMin','min'):out.append(str(st[-1][1]) if st else '-1')
print('\n'.join(out))
