
import sortedcontainers
q = int(input())
intervals = sortedcontainers.SortedList(key=lambda x: x[0])

def add(val):
    new = [val, val]

    to_remove = []
    for iv in intervals:
        if iv[1] + 1 < new[0]: continue
        if iv[0] > new[1] + 1: break
        new[0] = min(new[0], iv[0])
        new[1] = max(new[1], iv[1])
        to_remove.append(iv)
    for iv in to_remove:
        intervals.remove(iv)
    intervals.add(tuple(new))

for _ in range(q):
    parts = input().split()
    if parts[0] == 'addNum':
        add(int(parts[1]))
    else:
        print(' '.join('[%d,%d]' % (a, b) for a, b in intervals))
