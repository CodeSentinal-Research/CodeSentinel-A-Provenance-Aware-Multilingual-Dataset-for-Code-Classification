# problem title : Remove Duplicate Characters
# Keep only the first occurrence of each character.
s=input(); seen=set(); out=[]
for ch in s:
    if ch not in seen: seen.add(ch); out.append(ch)
print(''.join(out))
