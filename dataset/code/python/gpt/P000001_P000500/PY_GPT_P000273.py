# problem title : Valid Parentheses
# A stack matches each closing bracket with its most recent opening bracket.
s=input(); st=[]; pair={')':'(',']':'[','}':'{'}
for ch in s:
    if ch in '([{': st.append(ch)
    elif not st or st.pop()!=pair[ch]: print("Invalid"); break
else: print("Valid" if not st else "Invalid")
