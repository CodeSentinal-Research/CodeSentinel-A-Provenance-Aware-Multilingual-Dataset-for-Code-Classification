# PY_GPT_P001596 - Count Positive Numbers in a Range
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
    prefix.append(prefix[-1] + (value > 0))
answers = []
for _ in range(q):
    left, right = data[pos:pos + 2]
    pos += 2
    answers.append(prefix[right + 1] - prefix[left])
print(*answers, sep='\n')
