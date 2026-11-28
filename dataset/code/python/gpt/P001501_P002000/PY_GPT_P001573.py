# PY_GPT_P001573 - Count Windows With Sum Divisible by K
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
from collections import defaultdict
freq = defaultdict(int)
freq[0] = 1
rem = answer = 0
for x in a:
    rem = (rem + x) % k
    answer += freq[rem]
    freq[rem] += 1
print(answer)
