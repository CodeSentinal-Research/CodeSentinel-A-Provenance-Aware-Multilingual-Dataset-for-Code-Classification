import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    petrol = list(map(int, input_data[1:n+1]))
    dist = list(map(int, input_data[n+1:2*n+1]))
    deficit = 0
    curr = 0
    start = 0
    for i in range(n):
        curr += petrol[i] - dist[i]
        if curr < 0:
            start = i + 1
            deficit += curr
            curr = 0
    print(start if curr + deficit >= 0 else -1)
solve()
