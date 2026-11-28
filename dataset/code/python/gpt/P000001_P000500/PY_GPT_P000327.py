# problem title : Ransom Note
# Character counts in the magazine must cover every count required by the ransom note.
from collections import Counter
a=input();b=input(); print("Yes" if not (Counter(a)-Counter(b)) else "No")
