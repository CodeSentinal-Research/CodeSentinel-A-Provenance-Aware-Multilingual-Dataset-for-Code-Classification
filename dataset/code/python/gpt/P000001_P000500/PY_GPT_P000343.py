# problem title : Determine if String Are Almost Equivalent
# Compare all letter frequencies; every difference must be at most three.
from collections import Counter
a=Counter(input());b=Counter(input()); keys=set(a)|set(b);print("Yes" if all(abs(a[k]-b[k])<=3 for k in keys) else "No")
