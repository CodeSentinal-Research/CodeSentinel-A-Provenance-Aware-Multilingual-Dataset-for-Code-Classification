# problem title : Custom Sort String
# Emit characters in order of the custom alphabet, then append remaining characters.
order=input(); s=input(); from collections import Counter
c=Counter(s);out=[]
for ch in order: out.append(ch*c.pop(ch,0))
for ch,n in c.items(): out.append(ch*n)
print(''.join(out))
