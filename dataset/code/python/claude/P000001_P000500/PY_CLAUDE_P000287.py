
s=list(input());vowels='aeiouAEIOU'
v=[c for c in s if c in vowels]
j=len(v)-1
for i in range(len(s)):
    if s[i] in vowels: s[i]=v[j];j-=1
print(''.join(s))
