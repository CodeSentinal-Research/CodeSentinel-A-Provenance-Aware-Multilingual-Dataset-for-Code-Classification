import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    odd = [arr[i] for i in range(0, n, 2)]
    even = [arr[i] for i in range(1, n, 2)]
    print(" ".join(map(str, odd + even)))
solve()
