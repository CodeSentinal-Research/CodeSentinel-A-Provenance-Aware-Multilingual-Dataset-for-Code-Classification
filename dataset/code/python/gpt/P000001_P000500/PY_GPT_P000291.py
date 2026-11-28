# problem title : Permutation in String
# A permutation of S1 exists in S2 exactly when a window has equal counts.
from collections import Counter
a=input(); b=input(); m=len(a); need=Counter(a); print("Yes" if any(Counter(b[i:i+m])==need for i in range(len(b)-m+1)) else "No")
