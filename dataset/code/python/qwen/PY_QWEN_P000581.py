import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    a = list(map(int, input_data[1:n+1]))
    m = int(input_data[n+1])
    b = list(map(int, input_data[n+2:n+2+m]))
    print(" ".join(map(str, sorted(a + b))))
solve()
