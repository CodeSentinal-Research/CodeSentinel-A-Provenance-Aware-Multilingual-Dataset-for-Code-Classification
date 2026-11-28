import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    i = int(input_data[1+n])
    
    left = 2 * i + 1
    right = 2 * i + 2
    
    left_val = arr[left] if left < n else -1
    right_val = arr[right] if right < n else -1
    
    print(left_val, right_val)

if __name__ == "__main__":
    solve()

