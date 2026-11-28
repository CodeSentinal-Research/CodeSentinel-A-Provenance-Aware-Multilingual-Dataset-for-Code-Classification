
seen=set();res=[]
for c in input():
    if c not in seen: res.append(c);seen.add(c)
print(''.join(res))
