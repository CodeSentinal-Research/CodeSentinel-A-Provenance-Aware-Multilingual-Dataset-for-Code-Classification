import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    from collections import Counter
    c = Counter(arr)
    print(" ".join(map(str, [x for x in arr if c[x] == 1])))
solve()
