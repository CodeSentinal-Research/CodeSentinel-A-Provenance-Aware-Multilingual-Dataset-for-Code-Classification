# PY_GPT_P001586 - Maximum White Tiles Covered by a Carpet
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, carpet = data[:2]
tiles = []
pos = 2
for _ in range(n):
    start, end = data[pos:pos + 2]
    pos += 2
    tiles.append((start, end))
tiles.sort()
right = 0
covered = 0
answer = 0
for left in range(n):
    while right < n and tiles[right][1] - tiles[left][0] + 1 <= carpet:
        covered += tiles[right][1] - tiles[right][0] + 1
        right += 1
    partial = 0
    if right < n:
        carpet_end = tiles[left][0] + carpet - 1
        partial = max(0, carpet_end - tiles[right][0] + 1)
    answer = max(answer, covered + partial)
    if right > left:
        covered -= tiles[left][1] - tiles[left][0] + 1
print(answer)
