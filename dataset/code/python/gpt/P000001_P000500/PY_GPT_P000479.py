# problem title : Valid Parentheses
# Use a stack to verify that every closing parenthesis matches the latest opening one.
s=input();st=[];pair={')':'(',']':'[','}':'{'}
for ch in s:
 if ch in '([{':st.append(ch)
 elif not st or st.pop()!=pair[ch]:print('false');break
else:print('true' if not st else 'false')
