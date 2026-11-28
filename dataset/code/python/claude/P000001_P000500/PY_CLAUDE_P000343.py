
w1,w2=input().split()
from collections import Counter
c1=Counter(w1);c2=Counter(w2)
ok=all(abs(c1.get(c,0)-c2.get(c,0))<=3 for c in set(c1)|set(c2))
print('Yes' if ok else 'No')
