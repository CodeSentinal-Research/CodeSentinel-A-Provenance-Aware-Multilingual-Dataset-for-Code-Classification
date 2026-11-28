import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    # Last internal node is at index (n//2) - 1
    if n > 1:
        print(arr[(n // 2) - 1])
    else:
        print(arr[0])

if __name__ == "__main__":
    solve()

