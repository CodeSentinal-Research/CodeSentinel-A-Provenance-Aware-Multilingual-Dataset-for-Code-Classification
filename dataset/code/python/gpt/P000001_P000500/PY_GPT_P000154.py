# problem title : Find the Missing and Repeating Number
# Frequency counts reveal the value occurring twice and the missing value.
n = int(input()); a = list(map(int, input().split()))[:n]
from collections import Counter
count = Counter(a)
repeat = next(x for x in count if count[x] == 2)
missing = next(x for x in range(1, n + 1) if count[x] == 0)
print(missing, repeat)
