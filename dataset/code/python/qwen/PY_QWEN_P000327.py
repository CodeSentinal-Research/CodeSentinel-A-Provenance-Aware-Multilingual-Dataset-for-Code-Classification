ransom = input().strip()
mag = input().strip()
from collections import Counter
rc = Counter(ransom)
mc = Counter(mag)
print("Yes" if all(rc[k] <= mc[k] for k in rc) else "No")
