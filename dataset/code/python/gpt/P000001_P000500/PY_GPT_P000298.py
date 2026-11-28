# problem title : Longest Valid Parentheses
# A stack stores unmatched opening positions; the base index measures valid length.
s=input(); st=[-1]; best=0
for i,ch in enumerate(s):
    if ch=='(': st.append(i)
    else:
        st.pop()
        if not st: st.append(i)
        else: best=max(best,i-st[-1])
print(best)
