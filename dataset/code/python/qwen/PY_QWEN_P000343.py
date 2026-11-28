w1 = input().strip()
w2 = input().strip()
from collections import Counter
c1 = Counter(w1)
c2 = Counter(w2)
all_chars = set(c1.keys()).union(set(c2.keys()))
print("Yes" if all(abs(c1[c] - c2[c]) <= 3 for c in all_chars) else "No")
