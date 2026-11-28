import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    unique_ors = set()
    curr_ors = set()
    for x in nums:
        next_ors = {x}
        for y in curr_ors:
            next_ors.add(y | x)
        curr_ors = next_ors
        unique_ors.update(curr_ors)
    print(len(unique_ors))
solve()
