# problem title : Decode String
# Decode nested k[substring] expressions with a stack of repeat counts and partial strings.
s=input(); nums=[]; strs=['']; num=0
for ch in s:
    if ch.isdigit(): num=num*10+int(ch)
    elif ch=='[': nums.append(num); strs.append(''); num=0
    elif ch==']': strs[-2]+=strs.pop()*nums.pop()
    else: strs[-1]+=ch
print(strs[0])
