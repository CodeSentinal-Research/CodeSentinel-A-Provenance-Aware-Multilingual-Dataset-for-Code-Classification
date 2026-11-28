import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    arr = list(map(int, input_data[idx:idx+n])); idx += n
    
    for _ in range(q):
        i = int(input_data[idx]); idx += 1
        val = int(input_data[idx]); idx += 1
        arr[i] = val
        
    # Check Min Heap property
    is_valid = True
    for i in range(n):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] > arr[left]:
            is_valid = False
            break
        if right < n and arr[i] > arr[right]:
            is_valid = False
            break
            
    print("VALID" if is_valid else "INVALID")

if __name__ == "__main__":
    solve()

