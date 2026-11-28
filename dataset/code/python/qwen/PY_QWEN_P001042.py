import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    # Leaves are from index n//2 to n-1 in 0-indexed heap array
    start = n // 2
    print(*arr[start:])

if __name__ == "__main__":
    solve()

