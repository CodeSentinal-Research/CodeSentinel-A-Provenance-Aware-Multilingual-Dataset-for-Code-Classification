import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    target = int(input_data[0])
    print(target)
solve()
