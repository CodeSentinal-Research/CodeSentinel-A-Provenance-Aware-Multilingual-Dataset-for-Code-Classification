# problem title : First Unique Character in a String
# Count first, then return the earliest character whose count is one.
from collections import Counter
s=input();c=Counter(s);print(next((i for i,ch in enumerate(s) if c[ch]==1),-1))
