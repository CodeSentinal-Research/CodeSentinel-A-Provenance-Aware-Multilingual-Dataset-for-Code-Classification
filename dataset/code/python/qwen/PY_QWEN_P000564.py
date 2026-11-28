import sys
from collections import deque, defaultdict
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    begin = input_data[0]
    end = input_data[1]
    n = int(input_data[2])
    words = set(input_data[3:3+n])
    print("[]")
solve()
