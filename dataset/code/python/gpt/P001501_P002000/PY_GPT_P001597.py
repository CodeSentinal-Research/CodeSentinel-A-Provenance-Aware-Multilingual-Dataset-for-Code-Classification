# PY_GPT_P001597 - Count Elements Equal to X in a Range
# Problem-specific verified implementation.
import sys
from collections import defaultdict
data = list(map(int, sys.stdin.read().split()))
pos = 0
n = data[pos]
pos += 1
nums = data[pos:pos + n]
pos += n
q = data[pos]
pos += 1
from bisect import bisect_left, bisect_right
positions = defaultdict(list)
for index, value in enumerate(nums):
    positions[value].append(index)
answers = []
for _ in range(q):
    left, right, value = data[pos:pos + 3]
    pos += 3
    occurrence = positions[value]
    answers.append(bisect_right(occurrence, right) - bisect_left(occurrence, left))
print(*answers, sep='\n')
