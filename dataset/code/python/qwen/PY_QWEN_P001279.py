import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    
    result = ['a'] * n
    remaining = k - n
    
    for i in range(n - 1, -1, -1):
        add = min(25, remaining)
        result[i] = chr(ord('a') + add)
        remaining -= add
        
    print("".join(result))

if __name__ == "__main__":
    solve()

