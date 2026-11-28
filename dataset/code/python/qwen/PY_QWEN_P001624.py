import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    diff = list(map(int, input_data[1:1+n]))
    
    original = [0] * n
    original[0] = diff[0]
    for i in range(1, n):
        original[i] = original[i-1] + diff[i]
        
    print(*original)

solve()

