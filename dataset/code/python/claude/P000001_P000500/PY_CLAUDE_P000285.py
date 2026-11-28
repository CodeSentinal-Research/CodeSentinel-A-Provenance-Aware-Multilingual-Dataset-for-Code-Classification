
s1,s2=input().split();i=0
for c in s2:
    if i<len(s1) and s1[i]==c: i+=1
print('Yes' if i==len(s1) else 'No')
