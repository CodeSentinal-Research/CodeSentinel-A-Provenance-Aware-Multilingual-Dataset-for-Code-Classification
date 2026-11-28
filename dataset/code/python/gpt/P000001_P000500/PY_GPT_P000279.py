# problem title : Group Anagrams
# An anagram group shares the same sorted-character signature.
n=int(input()); groups={}
for _ in range(n):
    w=input(); groups.setdefault(''.join(sorted(w)),[]).append(w)
for g in groups.values(): print(*g)
