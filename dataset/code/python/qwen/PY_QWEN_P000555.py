import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    p = int(input_data[1])
    b = int(input_data[2])
    banned = set(map(int, input_data[3:3+b]))
    k = int(input_data[3+b])
    print("-1")
solve()
