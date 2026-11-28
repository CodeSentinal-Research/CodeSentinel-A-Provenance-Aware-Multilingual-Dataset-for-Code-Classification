import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    x = int(input_data[0])
    y = int(input_data[1])
    
    ops = 0
    while y > x:
        if y % 2 == 0:
            y //= 2
        else:
            y += 1
        ops += 1
        
    print(ops + x - y)

if __name__ == "__main__":
    solve()

