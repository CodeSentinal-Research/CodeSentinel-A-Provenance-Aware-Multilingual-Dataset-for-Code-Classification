import sys
import heapq
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    k = int(input_data[0])
    idx = 1
    lists = []
    for _ in range(k):
        sz = int(input_data[idx]); idx += 1
        lst = list(map(int, input_data[idx:idx+sz]))
        idx += sz
        if lst: lists.append(lst)
    h = []
    for i, lst in enumerate(lists):
        heapq.heappush(h, (lst[0], i, 0))
    res = []
    while h:
        val, lst_idx, elem_idx = heapq.heappop(h)
        res.append(val)
        if elem_idx + 1 < len(lists[lst_idx]):
            heapq.heappush(h, (lists[lst_idx][elem_idx+1], lst_idx, elem_idx+1))
    print(" ".join(map(str, res)))
solve()
