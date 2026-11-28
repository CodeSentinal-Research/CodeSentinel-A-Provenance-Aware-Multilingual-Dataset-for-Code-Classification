# problem title : Backspace String Compare
# Process backspaces with stacks, then compare the resulting strings.
def build(s):
 st=[]
 for ch in s:
  if ch=='#':
   if st:st.pop()
  else:st.append(ch)
 return ''.join(st)
a=input();b=input();print('true' if build(a)==build(b) else 'false')
