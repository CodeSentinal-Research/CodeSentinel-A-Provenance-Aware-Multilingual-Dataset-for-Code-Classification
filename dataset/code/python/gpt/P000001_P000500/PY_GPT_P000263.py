# problem title : Last Non-Repeating Character
# Scan from the end so the first unique character encountered is the last unique one.
s=input(); from collections import Counter
c=Counter(s); print(next((x for x in reversed(s) if c[x]==1),-1))
