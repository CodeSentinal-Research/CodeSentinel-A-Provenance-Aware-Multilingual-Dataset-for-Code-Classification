# problem title : Sort Array According to Frequency
# Frequency is the primary key; numerical value breaks equal-frequency ties.
n = int(input()); a = list(map(int, input().split()))[:n]
from collections import Counter
freq = Counter(a)
ordered = sorted(a, key=lambda x: (-freq[x], x))
print(*ordered)
