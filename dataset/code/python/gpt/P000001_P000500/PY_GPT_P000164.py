# problem title : Count Triplets with Given Sum
# Count triples efficiently by fixing one value and counting two-sum complements.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
from collections import Counter
answer = 0
for i in range(n - 2):
    freq = Counter(a[i + 1:])
    for j in range(i + 1, n - 1):
        need = target - a[i] - a[j]
        answer += freq.get(need, 0)
        freq[a[j]] -= 1
print(answer)
