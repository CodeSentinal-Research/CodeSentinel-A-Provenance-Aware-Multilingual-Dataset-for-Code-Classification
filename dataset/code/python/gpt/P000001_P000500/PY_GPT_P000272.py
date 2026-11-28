# problem title : Longest Common Prefix
# Shrink the common prefix whenever the next string disagrees.
n=int(input()); words=[input() for _ in range(n)]; pref=words[0]
for w in words[1:]:
    k=0
    while k<min(len(pref),len(w)) and pref[k]==w[k]: k+=1
    pref=pref[:k]
print(pref)
