
note,mag=input().split(' ',1)
from collections import Counter
cn=Counter(note);cm=Counter(mag)
print('Yes' if all(cn[c]<=cm[c] for c in cn) else 'No')
