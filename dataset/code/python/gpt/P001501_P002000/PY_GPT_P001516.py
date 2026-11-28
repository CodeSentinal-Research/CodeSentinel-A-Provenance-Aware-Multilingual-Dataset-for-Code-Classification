# PY_GPT_P001516 - Maximum White Tiles Covered by a Carpet
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, carpet = data[:2]
tiles = []
index = 2
for _ in range(n):
    start, end = data[index:index + 2]
    index += 2
    tiles.append((start, end))
tiles.sort()
starts = [item[0] for item in tiles]
right = 0
covered = 0
best = 0
for left in range(n):
    while right < n and tiles[right][1] - tiles[left][0] + 1 <= carpet:
        covered += tiles[right][1] - tiles[right][0] + 1
        right += 1
    partial = 0
    if right < n:
        end = tiles[left][0] + carpet - 1
        partial = max(0, end - tiles[right][0] + 1)
    best = max(best, covered + partial)
    if right > left:
        covered -= tiles[left][1] - tiles[left][0] + 1
    else:
        right = left + 1
print(best)
