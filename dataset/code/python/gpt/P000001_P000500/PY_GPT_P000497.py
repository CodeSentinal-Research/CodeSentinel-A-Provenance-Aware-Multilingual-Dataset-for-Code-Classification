# problem title : Remove Duplicate Letters
# Greedy monotonic construction keeps a lexicographically smallest subsequence with every letter once.
s=input();last={c:i for i,c in enumerate(s)};st=[];seen=set()
for i,ch in enumerate(s):
 if ch in seen:continue
 while st and ch<st[-1] and last[st[-1]]>i:seen.remove(st.pop())
 st.append(ch);seen.add(ch)
print(''.join(st))
