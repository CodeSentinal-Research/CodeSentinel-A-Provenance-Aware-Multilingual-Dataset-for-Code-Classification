# problem title : First Non-Repeating Character
# Count first, then scan in original order for the first frequency-one character.
s=input(); from collections import Counter
c=Counter(s); print(next((x for x in s if c[x]==1),-1))
