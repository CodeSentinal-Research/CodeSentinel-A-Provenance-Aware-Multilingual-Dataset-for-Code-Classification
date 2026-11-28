s = input().strip()
n = int(input())
words = [input().strip() for _ in range(n)]
from collections import defaultdict
wait = defaultdict(list)
for w in words:
    wait[w[0]].append((w, 0))
res = 0
for ch in s:
    next_wait = defaultdict(list)
    for w, i in wait[ch]:
        if i + 1 == len(w):
            res += 1
        else:
            next_wait[w[i+1]].append((w, i+1))
    wait = next_wait
print(res)
