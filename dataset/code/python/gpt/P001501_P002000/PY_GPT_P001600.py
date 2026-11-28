# PY_GPT_P001600 - Range Average Query
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
pos = 0
n = data[pos]
pos += 1
nums = data[pos:pos + n]
pos += n
q = data[pos]
pos += 1
prefix = [0]
for value in nums:
    prefix.append(prefix[-1] + value)
answers = []
for _ in range(q):
    left, right = data[pos:pos + 2]
    pos += 2
    total = prefix[right + 1] - prefix[left]
    answers.append(total / (right - left + 1))
print(*answers, sep='\n')
